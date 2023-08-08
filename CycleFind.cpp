vvi adj;
vi state, par;
int n,m;
 
void dfs(int v) {
    state[v] = 1;
    for (auto u : adj[v]) {
        if (state[u] == 0) {
            par[u] = v;
            dfs(u);
        } else if (state[u] == 1) {
            vi cycle;
            cycle.pb(u);
            while (u != v){
                cycle.pb(v);
                v = par[v];
            }
            cycle.pb(u);
            reverse(all(cycle));
            cout << cycle.size() << endl;
            for (auto x : cycle)
                cout << x + 1 << " ";
            cout << endl;
            exit(0);
        }
    }
    state[v] = 2;
}
 
 
void solve(){
    cin >> n >> m;
    adj.resize(n);
    par.rsz(n, -1); state.rsz(n, 0);
 
    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }
 
    for (int i=0; i<n; i++){
        if (state[i] == 0) dfs(i);
    }
    cout << "IMPOSSIBLE" << endl;
}