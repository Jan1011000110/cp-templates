const int S = 26;

struct Node {
  vector<int> nxt;
  bool is_word = 0;
  Node() {
    nxt.assign(S, -1);
  }
};

vector<Node> trie(1);

void add_str(string& s) {
  int v = 0;
  for (int i = 0; i < sz(s); i++) {
    int cur = s[i] - 'a';
    if (trie[v].nxt[cur] == -1) {
      trie[v].nxt[cur] = sz(trie);
      trie.emplace_back();
    }
    v = trie[v].nxt[cur];
    if (i == sz(s) - 1) {
      trie[v].is_word = true;
    }
  }
}

bool del_str(string& s, int i, int v) {
  int cnt = 0;
  for (int j = 0; j < S; j++) {
    if (trie[v].nxt[j] != -1) {
      cnt += 1;
    }
  }
  if (i == sz(s) - 1) {
    if (cnt == 0) {
      trie[v].is_word = 0;
      return true;
    }
    else {
      return false;
    }
  }
  else {
    if (del_str(s, i + 1, trie[v].nxt[s[i + 1] - 'a'])) {
      trie[v].nxt[s[i + 1] - 'a'] = -1;
      return cnt <= 1;
    }
    return false;
  }
}

