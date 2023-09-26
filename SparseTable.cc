// sparse table supports query in O(1) time just for min, max, gcd
// build in O(n * logn)
// doesn't support updates

const int LOG = 20; // ~10^5

void solve() {
  vector st(n, vector<int>(LOG));
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st[i][0] = x;
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  
  auto calc = [&](int l, int r) {
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
  };
}
