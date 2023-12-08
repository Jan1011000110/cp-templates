struct Hash {
	long long B;
	long long M;

	int n;
	vector<long long> pw;
	vector<long long> hash;

	void build(string s, long long B = 329483, long long M = 1027799999) {
		n = (int) s.size();
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

	long long get_hash() {
		return get_hash(0, n - 1);
	}
};

struct MultiHash {
	int COUNT_HASHES = 2;

	vector<long long> POLYS = {388293, 68};
	vector<long long> MODS = {1027799999, 998244353};

	int n;
	vector<Hash> hashes(COUNT_HASHES);

	void build(string s) {
		n = (int) s.size();
		for (int i = 0; i < COUNT_HASHES; ++i) {
			hashes[i].build(s, POLYS[i], MODS[i]);
		}
	}

	pair<long long, long long> get_hash(int left, int right) {
		return {hashes[0].get_hash(left, right), hashes[1].get_hash(left, right)};
	}

	pair<long long, long long> get_hash() {
		return get_hash(0, n - 1);
	}
};