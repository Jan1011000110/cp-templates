struct item {
  int key, prio, cnt, sum;
  item* l;
  item* r;
  item(int key_) : key(key_), prio(rand()), cnt(1), sum(key_), l(nullptr), r(nullptr) {}
};

typedef item* pitem;

int cnt(pitem t) {
  return not t ? 0 : t->cnt;
}

int sum(pitem t) {
  return not t ? 0 : t->sum;
}

void update(pitem t) {
  t->cnt = cnt(t->l) + cnt(t->r) + 1;
  t->sum = sum(t->l) + sum(t->r) + t->key;
}

void split(pitem t, int x, pitem &l, pitem &r) { // we split t into two parts, l contains all the nodes with key<=x 
  if (not t) {
    l = r = nullptr;
    return;
  }
  if (t->key <= x) {
    split(t->r, x, t->r, r);
    l = t;
  }
  else {
    split(t->l, x, l, t->l);
    r = t;
  }
  update(t);
}

void insert(pitem &t, pitem item) {
  if (not t) {
    t = item;
    return;
  }
  if (item->prio > t->prio) {
    split(t, item->key, item->l, item->r);
    t = item;
  }
  else {
    insert(t->key < item->key ? t->r : t->l, item);
  }
  update(t);
}

int query(pitem t, int k) {
  if (not t or k == 0) {
    return 0;
  }
  if (cnt(t->l) < k) {
    return t->key + sum(t->l) + query(t->r, k - cnt(t->l) - 1);
  }
  return query(t->l, k);
}

int query(pitem t, int l, int r) {
  return query(t, r) - query(t, l - 1);
}