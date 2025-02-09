struct node {
  const static int BITS = 31; // CHANGE THIS IN LONG LONGS
  vector<node*> nxt;
  int cnt;
  node() {
    nxt = vector<node*>(2, nullptr);
    cnt = 0;
  }
 
  void insert(int x, int i = BITS) {
    cnt += 1;
    if (i == -1) return;
    int bit = (x >> i & 1);
    if (not nxt[bit]) {
      nxt[bit] = new node();
    }
    nxt[bit]->insert(x, i - 1);
  } 
 
  void erase(int x, int i = BITS) {
    cnt -= 1;
    if (i == -1) return;
    int bit = (x >> i & 1);
    nxt[bit]->erase(x, i - 1);
    if (nxt[bit]->cnt == 0) {
      delete nxt[bit];
      nxt[bit] = nullptr;
    }
  }
 
  int search(int x, int i = BITS) {
    if (i == -1) return 0;
    int bit = (x >> i & 1);
    if (nxt[bit^1] and nxt[bit^1]->cnt > 0) {
      return (1 << i) + nxt[bit^1]->search(x, i - 1);
    }
    else {
      if (not nxt[bit]) return 0;
      return nxt[bit]->search(x, i - 1);
    }
  }
};