struct CD {
  int n;
  vector<vector<int>> g;
  vector<int> siz;
  vector<int> par;
  vector<int> used;
  
  CD(int n_) {
    n = n_;
    g.assign(n, {});
    siz.resize(n);
    par.assign(n, -1);
    used.resize(n);
  }
  
  void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  void find_size(int v, int p) {
    siz[v] = 1;
    for (auto u : g[v]) {
      if (u != p and not used[u]) {
        find_size(u, v);
        siz[v] += siz[u];
      }
    }
  }
  
  int find_centroid(int v, int p, int tot) {
    for (auto u : g[v]) {
      if (u != p and not used[u] and siz[u] > tot / 2 ) {
        return find_centroid(u, v, tot);
      }
    }
    return v;
  }
  
  void build(int v, int p) {
    find_size(v, -1);
    int centroid = find_centroid(v, -1, siz[v]);
    
    par[centroid] = p;
    used[centroid] = 1;
    
    for (auto u : g[centroid]) {
      if (not used[u]) {
        build(u, centroid);
      }
    }
  }
};
