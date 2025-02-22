vector<int> KMP(const string &s) {
	vector<int> pi(sz(s));
	for (int i = 1; i < sz(s); ++i) {
		int j = pi[i - 1];
		while (j > 0 and s[j] != s[i]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j += 1;
		}
		pi[i] = j;
	}
	return pi;
}