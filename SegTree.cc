template<typename T>
struct segTree {
  int size = 1;
  T null_value = 0;
  vector<T> t;

  segTree(int n) {
    while (size < n) size *= 2;
    t.assign(2*size, null_value);
  }

  T merge(T a, T b) {
    return a + b;
  }

  void modify(int v, int l, int r, int x, T k) {
    if (r - l == 1) {
      t[v] = k;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) {
      modify(2*v + 1, l, m, x, k);
    }
    else {
      modify(2*v + 2, m, r, x, k);
    }
    t[v] = merge(t[2*v + 1], t[2*v + 2]);
  }

  void modify(int x, T k) {
    modify(0, 0, size, x, k);
  }

  T query(int v, int l, int r, int x, int y) {
    if (l >= x and r <= y) {
      return t[v];
    }
    if (l >= y or r <= x) {
      return null_value;
    }
    int m = (l + r) / 2;
    return merge(query(2*v + 1, l, m, x, y), query(2*v + 2, m, r, x, y));
  }

  T query(int x, int y) {
    return query(0, 0, size, x, y);
  }
};