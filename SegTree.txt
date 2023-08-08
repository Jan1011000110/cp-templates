template<typename T>
struct segTree {
  int size = 1; 
  int null_value = 0; // CHANGE THIS
  vector<int> t;
  segTree(int n) {
    while (size < n) size *= 2;
    t.assign(2 * size, null_value);
  }
  int merge(int a, int b) { // CHANGE THIS
    return a + b;
  }
  void modify(int i, int x, int tl, int tr, int k) {
    if (tr - tl == 1) {
      t[x] = k;
      return;
    }
    int m = (tl + tr) / 2;
    if (i < m) {
      modify(i, 2 * x + 1, tl, m, k);
    } else {
      modify(i, 2 * x + 2, m, tr, k);
    }
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void modify(int i, int k) {
    modify(i, 0, 0, size, k);
  }
  
  int query(int l, int r, int x, int tl, int tr) {
    if (tl >= l && tr <= r) {
      return t[x];
    }
    if (tl >= r || tr <= l) {
      return null_value;
    }
    int m = (tl + tr) / 2;
    return merge(query(l, r, 2 * x + 1, tl, m), query(l, r, 2 * x + 2, m, tr));
  }
  int query(int l, int r) {
    return query(l, r, 0, 0, size);
  }
};
