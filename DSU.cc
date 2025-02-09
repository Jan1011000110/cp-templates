struct DSU {
  vector<int> f, siz;

  DSU(int n) {
    f = vector<int>(n);
    iota(f.begin(), f.end(), 0);
    siz = vector<int>(n, 1);
  }

  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    f[y] = x;
    siz[x] += siz[y];
    return true;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  int size(int x) { return siz[find(x)]; } 
};