void solve() {
  int n, m;
  cin >> n >> m;
  vector g(n, vector<pair<int,int>>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    --x; --y;
    g[x].emplace_back(y, w);
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(n, INF);
  dist[0] = 0;
  pq.push({0, 0});
  
  while (not pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (d > dist[v]) continue;
    for (auto [u, w] : g[v]) {
      if (dist[v] + w < dist[u]) {
        dist[u] = dist[v] + w;
        pq.push({dist[u], u});
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}
