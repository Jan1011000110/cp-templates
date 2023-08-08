struct matrix {
  int n, m;
  vector<vector<int>> a;
  matrix(int n_, int m_) {
    n = n_; 
    m = m_;
    a.resize(n, vector<int>(m));
  }
  
  matrix operator *(matrix other) {
    matrix C = matrix(N, N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          C.a[i][j] += a[i][k] * other.a[k][j];
        }
      }
    }
    return C;
  }
};

matrix pow(matrix& A, int b) {
  matrix C(N, N);
  for (int i = 0; i < N; i++) C.a[i][i] = 1;
  
  while (b > 0) {
    if (b & 1) {
      C = C * A;
    }
    A = A * A;
    b >>= 1;
  }
  return C;
}
