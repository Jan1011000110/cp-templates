
struct Dinic {
  using T = long long;

  struct Edge {
    int to;
    T flow, cap;
  };

  int n, s, t;
  vector<Edge> edges;
  vector<vector<int>> g;
  vector<int> level, ptr;

  Dinic(int n_, int s_, int t_) : n(n_), s(s_), t(t_) {
    g = vector<vector<int>>(n);
    ptr = vector<int>(n, 0);
  }

  void add_edge(int v, int u, int cap) {
    int id = (int) edges.size();
    g[v].push_back(id);
    edges.push_back({u, 0, cap});
    g[u].push_back(id + 1);
    edges.push_back({v, 0, 0});
  }

  bool bfs() {
    level = vector<int>(n, -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (not q.empty()) {
      int v = q.front();
      q.pop();
      for (auto id : g[v]) {
        Edge e = edges[id];
        if (e.cap - e.flow > 0 and level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }  
      }
    }
    return level[t] != -1;
  }

  T dfs(int v, int add_flow) {
    if (v == t) {
      return add_flow;
    }
    for (int &it = ptr[v]; it < (int) g[v].size(); ++it) {
      int id = g[v][it];
      Edge e = edges[id];
      if (e.cap - e.flow > 0 and level[e.to] == level[v] + 1) {
        int real_flow = dfs(e.to, min(add_flow, e.cap - e.flow));
        if (real_flow == 0) {
          continue;
        }
        edges[id].flow += real_flow;
        edges[id ^ 1].flow -= real_flow;
        return real_flow;
      }
    }
    return 0;
  }

  T max_flow() {
    T flow = 0;
    while (bfs()) {
      ptr = vector<int>(n, 0);
      while (true) {
        T add_flow = dfs(s, numeric_limits<T>::max());
        if (add_flow == 0) {
          break;
        }
        flow += add_flow;
      }
    }
    return flow;
  }
};