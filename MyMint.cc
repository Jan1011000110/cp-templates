const int mod = 1e9+7;
struct Mint {
  long long n;
  Mint() : n(0) {}
  Mint(long long n_) {
    n = n_%mod;
    if (n < 0) n += mod;
  }
  operator int() { return n; }
  Mint pow(long long b) { Mint x = n, y = 1; for (; b; b >>= 1) { if (b & 1) y *= x; x *= x; } return y; }
  Mint inv() { return pow(mod - 2); }
  
  Mint operator +(Mint m) { long long s = n + m.n; if (s >= mod) s -= mod; return s; }
  Mint operator +=(Mint m) { return n = n + m.n; }
  Mint operator -(Mint m) { long long s = n - m.n; if (s < 0) s += mod; return s; }
  Mint operator -=(Mint m) { return  n = n - m.n; }
  Mint operator *(Mint m) { long long s = (1LL * n * m.n) % mod; return s; }
  Mint operator *=(Mint m) { return n = n * m.n; }
  Mint operator /(Mint m) { long long s = n * m.inv(); return s; }
  Mint operator /=(Mint m) { return n = n / m.n; }
  
  bool operator ==(Mint m) { return n == m.n; }
  bool operator !=(Mint m) { return n != m.n; }
  bool operator <(Mint m) { return n < m.n; }
  bool operator >(Mint m) { return n > m.n; }
  
  friend ostream& operator <<(ostream& out, Mint m) { return out << m.n; }
};
