struct Basis {
  const int B = 31; // change this, care long long
  vector<int> basis; 
  Basis() : basis(vector<int>(B, -1)) {}
  void add_base(int x) {
    for (int i = B - 1; i >= 0; --i) {
      if (x >> i & 1) {
        if (basis[i] == -1) {
          basis[i] = x;
          return;
        }
        x ^= basis[i];
      }
    }
  }
};