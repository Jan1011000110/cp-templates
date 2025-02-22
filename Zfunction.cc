vector<int> z_function(const string &s) {
	vector<int> z(sz(s));
	int l = 0, r = 0;
	for (int i = 1; i < sz(s); ++i) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < sz(s) and s[z[i]] == s[i + z[i]]) {
			z[i] += 1;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}