vector<int> tin, low, used;
int timer;

void Dfs(int v, int p) {
  tin[v] = low[v] = timer++;
  for (auto u : g[v]) {
    if (u == p) continue;
    if (used[u]) {
      low[v] = min(low[v], tin[u]);
    }
    else {
      Dfs(u, v);
      low[v] = min(low[v], low[u]);
      if (low[v] < low[u]) {
        // process edge (v, u)
      }
    }
  }
}

void Bridges() {
  timer = 0;
  tin.assign(n, -1);
  low.assign(n, -1);
  used.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    Dfs(i);
  }
}
