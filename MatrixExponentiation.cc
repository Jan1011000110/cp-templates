template<typename T = long long>
struct Matrix {
  int n;
  vector<vector<T>> m;

  Matrix(int n_) : n(n_), m(n, vector<T>(n)) {}

  Matrix(int n_, T val) : Matrix(n_) {
    for (int i = 0; i < n; ++i) m[i][i] = val;
  }

  Matrix<T> operator * (Matrix<T> &other) {
    Matrix<T> res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          res.m[i][j] += m[i][k] * other.m[k][j];
        }
      }
    }
    return res;
  }
};

template<typename T = long long, typename X = long long>
Matrix<T> matpow(Matrix<T> a, X b) {
  Matrix<T> res(a.n, 1);
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}


template<typename T = long long>
struct Matrix {
  int n;
  vector<vector<T>> m;

  Matrix(int n_) : n(n_), m(n, vector<T>(n)) {}

  Matrix(int n_, T val) : Matrix(n_) {
    for (int i = 0; i < n; ++i) m[i][i] = val;
  }

  Matrix<T> operator * (Matrix<T> other) {
    Matrix<T> res;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          res.m[i][j] += m[i][k] * other.m[k][j];
        }
      }
    }
    return res;
  }
};


template<typename T = long long, X = long long>
Matrix<T> matpow(Matrix<T> a, X b) {
  Matrix res(a.n, 1);
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}