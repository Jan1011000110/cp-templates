// CHT in O(nlogn) (query points in any order) !!! SHORT IMPLEMENTATION
struct line {
  int m, b;

  line(int m_ = 0, int b_ = 0) : m(m_), b(b_) {}

  int f(int x) {
    return m * x + b;
  }
};

vector<line> lines;
bool check(line x, line y, line z) {
  return (__int128)(x.b - z.b) * (x.m - y.m) <= (__int128)(x.b - y.b) * (x.m - z.m); // CHANGE INEQUALITY IF ITS MAX
}
 
void add(line l) {
  while (sz(lines) >= 2 and check(end(lines)[-1], end(lines)[-2], l))
    lines.pop_back();
  lines.push_back(l);
}
 
int query(int x) {
  int l = 0, r = sz(lines) - 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (lines[mid].f(x) >= lines[mid + 1].f(x)) l = mid + 1; // CHANGE INEQUALITY IF ITS MAX
    else r = mid;
  }
  return min(lines[l].f(x), lines[r].f(x)); // CHANGE MIN TO MAX
}


// CHT in O(nlogn) (query points in any order)
struct CHT {
  struct line {
    int m, b;

    line() {}
    line(int m_, int b_) : m(m_), b(b_) {}

    double isect(line l) {
      return (double)(l.b - b) / (double)(m - l.m);
    }

    int f(int x) {
      return m * x + b;
    }
  };

  vector<double> x;
  vector<line> lines;

  CHT() {}
  CHT(line l) {
    x.push_back(-INF);
    lines.push_back(l);
  }

  void addLine(line l) {
    while (sz(lines) >= 2 and l.isect(lines.back()) <= x.back()) {
      x.pop_back();
      lines.pop_back();
    }
    if (not lines.empty()) {
      x.push_back(l.isect(lines.back()));
    }
    lines.push_back(l);
  }

  int query(int i) {
    int id = upper_bound(x.begin(), x.end(), i) - x.begin();
    --id;
    return lines[id].f(i);
  }
};


// CHT in O(n) (query points in decreasing order)
struct CHT {
  struct line {
    int m, b;

    line() {}
    line(int m_, int b_) : m(m_), b(b_) {}

    double isect(line l) {
      return (double)(l.b - b) / (double)(m - l.m);
    }

    int f(int x) {
      return m * x + b;
    }
  };

  deque<line> lines;

  CHT() {}
  CHT(line l) {
    x.push_back(-INF);
    lines.push_back(l);
  }

  void addLine(line l) {
  	
  }

  int query(int x) {
  	while (sz(lines) >= 2 and end(lines)[-1].f(i) <= end(lines)[-2].f(i)) {
  	  lines.pop_back();
  	}
  	return lines.back().f(i);
  }
};