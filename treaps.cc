typedef struct item* pitem;

struct item {
  char c;
  int prio, cnt;
  bool rev;
  pitem l, r;
  item(char c_) : c(c_), prio(rand()), cnt(1), rev(false), l(nullptr), r(nullptr) {}
};

int cnt(pitem t) {
  return not t ? 0 : t->cnt;
}

void update(pitem t) {
  t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

void push(pitem t) {
  if (t and t->rev) {
    t->rev = false;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
  }
}

void split(pitem t, pitem &l, pitem &r, int x) { // we split t into two parts, l contains all the nodes with key<=x 
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

void reverse(pitem t, int l, int r) {
  pitem t1, t2, t3;
  split(t, t1, t2, l);
  split(t2, t2, t3, r - l + 1);
  t2->rev ^= 1;
  merge(t, t1, t2);
  merge(t, t, t3);
}

void output(pitem t) {
  if (not t) return;
  push(t);
  output(t->l);
  cout << t->c;
  output(t->r);
}