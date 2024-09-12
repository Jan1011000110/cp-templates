template <typename T>
struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  void read() {
    cin >> x >> y;
  }

  friend Point operator - (const Point& a, const Point& b) { return Point(a.x - b.x, a.y - b.y); }

  friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
  friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; } // cross(a,b)<=0 <=> b is on r of a
};