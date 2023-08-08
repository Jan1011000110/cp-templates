using Int = __int128;

const long double eps = 1e-8;

struct P {
  int x, y;
  P() : x(0), y(0) {}
  P(const Int& x_, const Int& y_) : x(x_), y(y_) {}
  
  bool operator ==(const P& p) const {
    return abs(x - p.x) <= eps and abs(y - p.y) <= eps;
  }
  
  P operator +(const P& p) const { 
    return P(x + p.x, y + p.y);
  }
  P operator -(const P& p) const { 
    return P(x - p.x, y - p.y);
  }
  P operator *(const int& k) const { 
    return P(x * k, y * k);
  }
  Int operator *(const P& p) const {
    return (Int) x * p.x + (Int) y * p.y;
  }
  Int operator ^(const P& p) const {
    return (Int) x * p.y - (Int) y * p.x; 
  }

  P& operator +=(const P& p) {
    x += p.x; y += p.y; return *this;
  }
  P& operator -=(const P& p) {
    x -= p.x; y -= p.y; return *this;
  }
  P& operator *=(const P& p) {
    x *= p.x; y *= p.y; return *this;
  }
  
  Int norm() const {
    return (Int) (*this) * (*this);
  }
  long double len() const {
    return sqrtl(norm());
  }
};


double angle(const P& p1, const P& p2) {
  return acosl((p1 * p2) / (p1.len() * p2.len()));
}
int intersection(const P& p1, const P& d1, const P& p2, const P& d2) {
  return ((p2 - p1) ^ d2) / (d1 ^ d2);
}
