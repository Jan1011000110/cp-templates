struct fenwTree {
  int n;
  vector<int> fen;
  void init(int N) {
    n = N;
    fen.assign(n + 1, 0LL);
  }
  void add(int v, int x) {
    for (v = v + 1; v <= n; v += v & -v) {
      fen[v] += x;
    }
  }
  int sum(int v) {
    int s = 0;
    for (v = v + 1; v > 0; v -= v & -v) {
      s += fen[v];
    }
    return s;
  }
  int range(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};
