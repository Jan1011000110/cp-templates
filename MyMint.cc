struct mint {
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mint &operator+=(mint &a, mint b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mint &operator-=(mint &a, mint b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((long long)a.v * b.v); }
mint &operator*=(mint &a, mint b) { return a = a * b; }
mint pow(mint a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mint operator/(mint a, mint b) { return a * inv(b); }
ostream &operator<<(ostream &os, const mint &m) {
  return os << m.v;
}