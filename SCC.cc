
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n), rev_g(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		rev_g[y].push_back(x);
	}
	
	vector<int> order, used(n);

	function<void(int)> topo = [&](int v) {
		used[v] = 1;
		for (auto u : g[v]) {
			if (not used[u]) {
				topo(u);
			}
		}
		order.push_back(v);
	};

	for (int i = 0; i < n; ++i) {
		if (not used[i]) {
			topo(i);
		}
	}
	reverse(order.begin(), order.end());

	vector<int> root(n, -1);
	function<void(int, int)> dfs = [&](int v, int org) {
		root[v] = org;
		for (auto u : rev_g[v]) {
			if (root[u] == -1) {
				dfs(u, org);
			}
		}
	};

	for (auto i : order) {
		if (root[i] == -1) {
			dfs(i, i);
		}
	}

	vector<vector<int>> scc(n);
	for (int v = 0; v < n; ++v) {
		for (auto u : g[v]) {
			if (root[v] != root[u]) {
				scc[root[v]].push_back(root[u]);
			}
		}
	}
}