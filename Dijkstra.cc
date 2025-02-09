auto dijkstra = [&]() {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  for (int i = 0; i < n; ++i) {
    pq.emplace(dist[i], i);
  }
  while (not pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (d > dist[v]) continue;
    for (auto [u, w] : g[v]) {
      if (dist[v] + w < dist[u]) {
        dist[u] = dist[v] + w;
        pq.emplace(dist[u], u);
      }
    }
  }
};