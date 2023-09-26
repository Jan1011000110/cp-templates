const ll N = 2e5+5, INF = 1e18, MOD = 1e9+7;

vector<int> fact(N), inv_fact(N);

int mult(int a, int b) {
  return (a * b) % MOD;
}
int add(int a, int b) {
  return (a + b) % MOD;
}
int mpow(int a, int b) {
  return not b ? 1 : mult(mpow(mult(a, a), b / 2), (b & 1 ? a : 1));
}
int inv(int a) {
  return mpow(a, MOD - 2);
}
int C(int a, int b) {
  if (b > a) return 0;
  return mult(fact[a], mult(inv_fact[b], inv_fact[a - b]));
}

void init() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
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
