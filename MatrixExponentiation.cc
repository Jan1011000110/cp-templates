template<typename T = long long>
struct Matrix {
  int n;
  vector<vector<T>> m;
  
  Matrix(int n_) {
    n = n_; 
    m = vector<vector<T>>(n, vector<T>(n));
  }
  
  Matrix(int n_, T val) {
    n = n_;
    m = vector<vector<T>>(n, vector<T>(n));
    for (int i = 0; i < n; i++) m[i][i] = val;
  }
  
  Matrix<T> operator * (const Matrix<T> &other) {
    Matrix<T> res(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          res.m[i][j] += m[i][k] * other.m[k][j];
        }
      }
    }
    return res;
  }
};

template<typename T = long long, typename X = int>
Matrix<T> matpow(Matrix<T> a, X b) {
  Matrix<T> res(a.n, 1);
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}