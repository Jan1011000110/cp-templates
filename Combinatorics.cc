const ll INF = 1e18, MOD = 1e9+7;

vector<int> fact, inv_fact;

int mult(int a, int b) {
  return (1LL * a * b) % MOD;
}

int add(int a, int b) {
  return (a + b) % MOD;
}

int sub(int a, int b) {
  return ((a - b) % MOD + MOD) % MOD;
}

int mpow(int a, ll b) {
  return not b ? 1LL : mult(mpow(mult(a, a), b >> 1), (b & 1 ? a : 1LL));
}

int inv(int a) {
  return mpow(a, MOD - 2);
}

int C(int a, int b) {
  if (b > a) return 0;
  return mult(fact[a], mult(inv_fact[b], inv_fact[a - b]));
}

void init(int N) {
  fact = vector<int>(N+1);
  inv_fact = vector<int>(N+1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = mult(fact[i - 1], i);
    inv_fact[i] = inv(fact[i]);
  }
}