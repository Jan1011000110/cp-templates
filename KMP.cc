vector<int> KMP(const string &s) {
	int n = int(s.size());
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
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