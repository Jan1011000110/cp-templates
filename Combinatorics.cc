const long long INF = 1e18, MOD = 1e9+7;

vector<long long> fact, inv_fact;

long long mult(long long a, long long b) {
  return (a * b) % MOD;
}
long long add(long long a, long long b) {
  long long s = a + b;
  while (s >= MOD) s -= MOD;
  return s;
}
long long sub(long long a, long long b) {
  long long s = a - b;
  while (s < 0) s += MOD;
  return s;
}
long long mpow(long long a, long long b) {
  return not b ? 1LL : mult(mpow(mult(a, a), b / 2), (b & 1 ? a : 1LL));
}
long long inv(long long a) {
  return mpow(a, MOD - 2);
}
long long C(long long a, long long b) {
  if (b > a) return 0;
  return mult(fact[a], mult(inv_fact[b], inv_fact[a - b]));
}

void init(int N) {
  fact = vector<long long>(N+1);
  inv_fact = vector<long long>(N+1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = mult(fact[i - 1], i);
    inv_fact[i] = inv(fact[i]);
  }
}
 
 
void solve(){

}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1; 
	cin >> tt;
	while(tt--) {
    solve();
	}
	return 0;
}
