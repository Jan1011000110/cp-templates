int phi(int n) {
	int ans = n;
	for (int d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			while (n % d == 0) {
				n /= d;
			}
			ans = ans - ans / d;
		}
	}
	return ans;
}