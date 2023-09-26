const int S = 26;

struct Node {
  vector<int> nxt;
  int cnt = 0;
  bool is_word;
  Node() {
    nxt.assign(S, -1);
    is_word = false;
    cnt = 0;
  }
};

vector<Node> trie(1);

void insert(string& s) {
  int v = 0;
  for (int i = 0; i < sz(s); i++) {
    int cur = s[i] - 'a';
    if (trie[v].nxt[cur] == -1) {
      trie[v].nxt[cur] = sz(trie);
      trie.emplace_back();
    }
    v = trie[v].nxt[cur];
    trie[v].cnt += 1;
    if (i == sz(s) - 1) {
      trie[v].is_word = true;
    }
  }
}

