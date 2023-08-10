struct Matrix {
  int n;
  vector<vector<int>> m;
  
  Matrix(int n_) {
    n = n_; 
    m = vector<vector<int>>(n, vector<int>(n));
  }
  
  Matrix(int n_, int val) {
    n = n_;
    m = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) m[i][i] = val;
  }
  
  Matrix operator *(Matrix& other) {
    Matrix res(n);
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

Matrix matpow(Matrix& a, int b) {
  Matrix res(a.n, 1);
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
