typedef struct item* pitem;

struct item {
  int prio, cnt, val, sum;
  bool rev;
  pitem l, r;
  item(int val_) : prio(rand()), cnt(1), val(val_), sum(val_), rev(false), l(nullptr), r(nullptr) {}
};

int cnt(pitem t) {
  return not t ? 0 : t->cnt;
}

int sum(pitem t) {
  return not t ? 0 : t->sum;
}

void update(pitem t) {
  t->cnt = cnt(t->l) + cnt(t->r) + 1;
  t->sum = sum(t->l) + sum(t->r) + t->val;
}

void push(pitem t) {
  if (t and t->rev) {
    t->rev = false;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
  }
}

void split(pitem t, pitem &l, pitem &r, int x) {
  push(t);
  if (not t) {
    l = r = nullptr;
    return;
  }
  if (cnt(t->l) + 1 <= x) {
    split(t->r, t->r, r, x - cnt(t->l) - 1);
    l = t;
  }
  else {
    split(t->l, l, t->l, x);
    r = t;
  }
  update(t);
}

void merge(pitem &t, pitem l, pitem r) {
  push(l);
  push(r);
  if (not l or not r) {
    t = l ? l : r;
    return;
  }
  if (l->prio > r->prio) {
    merge(l->r, l->r, r);
    t = l;
  }
  else {
    merge(r->l, l, r->l);
    t = r;
  }
  update(t);
}

int query(pitem t, int x) {
  push(t);
  if (not t or x == 0) {
    return 0;
  }
  if (cnt(t->l) + 1 <= x) {
    return sum(t->l) + t->val + query(t->r, x - cnt(t->l) - 1);
  }
  else {
    return query(t->l, x);
  }
}

int query(pitem t, int l, int r) {
  return query(t, r) - query(t, l - 1);
}

void reverse(pitem &t, int l, int r) {
  pitem t1, t2, t3;
  split(t, t1, t2, l - 1);
  split(t2, t2, t3, r - l + 1);
  t2->rev ^= 1;
  merge(t, t1, t2);
  merge(t, t, t3);
}