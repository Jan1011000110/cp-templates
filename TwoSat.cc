struct TwoSat {
  int n;
  vector<vector<int>> g, g_inv;
  vector<int> used, order, comp, assignment;

  TwoSat(int _n) : n(_n), g(2 * n), g_inv(2 * n), used(2 * n), comp(2 * n, -1), assignment(n) {};

  void topo(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
      if (used[u]) continue;
      topo(u);
    }
    order.emplace_back(v);
  }

  void dfs(int v, int c) {
    comp[v] = c;
    for (auto u : g_inv[v]) {
      if (comp[u] != -1) continue;
      dfs(u, c);
    }
  }

  bool solve() {
    order.clear();
    used.assign(2 * n, 0);
    for (int i = 0; i < 2 * n; ++i) {
      if (not used[i]) {
        topo(i);
      }
    }
    reverse(order.begin(), order.end());
    int j = 0;
    for (auto i : order) {
      if (comp[i] == -1) {
        dfs(i, j++);
      }
    }
    assignment.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      if (comp[2 * i] == comp[2 * i ^ 1]) {
        return false;
      } 
      assignment[i] = comp[2 * i] > comp[2 * i ^ 1];
    }
    return true;
  }

  void add_edge(int a, int b) {
    g[a].emplace_back(b);
    g_inv[b].emplace_back(a);
  }

  void add_clause(int a, int na, int b, int nb) {
    a = 2 * a ^ na;
    b = 2 * b ^ nb;
    add_edge(a ^ 1, b);
    add_edge(b ^ 1, a);
  }
};