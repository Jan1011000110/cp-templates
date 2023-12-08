struct Hash {
	long long B = 32478
	long long M = 1027799999;

	int n;
	vector<int> pw;
	vector<int> hash;

	void build(string s) {
		n = int(s.size());
		pw = vector<long long>(n + 1);
		hash = vector<long long>(n + 1);

		pw[0] = 1;
		for (int i = 1; i <= n; ++i) {
			pw[i] = (pw[i - 1] * B) % M;
		}

		for (int i = 0; i < n; ++i) {
			hash[i + 1] = ((hash[i] * B) % M + s[i]) % M;
		}
	}
	
	long long get_hash(int left, int right) {
		return ((hash[right + 1] - (hash[left] * pw[right - left + 1]) % M) + M) % M;
	}
};