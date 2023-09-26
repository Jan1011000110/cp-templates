struct segTree {
  int size = 1; 
  int null_value = 0; // CHANGE THIS
  vector<int> t, upd;
  
  segTree(int n) {
    while (size < n) size *= 2;
    t.assign(2 * size, null_value);
    upd.assign(2 * size, 0LL);
  }
  
  int merge(int a, int b) { // CHANGE THIS
    return a + b;
  }
  
  void propagate(int x, int tl, int tr) {
    if (upd[x] == 0 or tr - tl == 1) {
      return;
    }
    int m = (tl + tr) / 2;
    t[2 * x + 1] += upd[x] * (m - tl);
    t[2 * x + 2] += upd[x] * (tr - m);
    upd[2 * x + 1] += upd[x];
    upd[2 * x + 2] += upd[x];
    upd[x] = 0;
  }
  
  void modify(int l, int r, int x, int tl, int tr, int k) {
    propagate(x, tl, tr);
    if (tl >= l and tr <= r) {
      t[x] += (tr - tl) * k;
      upd[x] += k;
      return;
    }
    if (tl >= r or tr <= l) {
      return;
    }
    int m = (tl + tr) / 2;
    modify(l, r, 2 * x + 1, tl, m, k);
    modify(l, r, 2 * x + 2, m, tr, k);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  
  void modify(int l, int r, int k) {
    modify(l, r, 0, 0, size, k);
  }
  
  int query(int l, int r, int x, int tl, int tr) {
    propagate(x, tl, tr);
    if (tl >= l and tr <= r) {
      return t[x];
    }
    if (tl >= r or tr <= l) {
      return null_value;
    }
    int m = (tl + tr) / 2;
    return merge(query(l, r, 2 * x + 1, tl, m), query(l, r, 2 * x + 2, m, tr));
  }
  
  int query(int l, int r) {
    return query(l, r, 0, 0, size);
  }
};
