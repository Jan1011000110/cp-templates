struct DSU {
  vector<int> f, siz;
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }
  int leader(int x) {
    return f[x] == x ? x : f[x] = leader(f[x]);
  }
  bool same(int x, int y) {
    return leader(x) == leader(y);
  }
  bool merge(int x, int y) {
    x = leader(x); y = leader(y);
    if (x == y) return false;
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) {
    return siz[leader(x)];
  }
};
