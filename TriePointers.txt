const int S = 26;

struct node {
  vector<node*> nxt;
  int is_word = 0;
  node () {
    nxt.assign(S, nullptr);
  }
};

void add_str(node* root, string& s, int idx) {
  if (idx == sz(s)) {
    root->is_word += 1;
    return;
  }
  
  int cur = s[idx] - 'a';
  if (!root->nxt[cur]) {
    root->nxt[cur] = new node;
  }
  add_str(root->nxt[cur], s, idx + 1);
}

bool del_str(node* root, string& s, int idx) {
  int cnt = 0;
  for (int i = 0; i < S; i++) 
    if (root->nxt[i]) cnt += 1;
  
  if (idx == sz(s)) {
    if (cnt == 0) {
      root->is_word -= 1;
    }
    return cnt == 0;
  }
  else {
    int cur = s[idx] - 'a';
    if (del_str(root->nxt[cur], s, idx + 1)) {
      root->nxt[cur] = nullptr;
      return cnt <= 1;
    }
    return false;
  }
}
