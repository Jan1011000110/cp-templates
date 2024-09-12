bool isPrime(ll n) { 
  if (n <= 1) return false; 
  if (n <= 3) return true; 
    
  if (n % 2 == 0 || n % 3 == 0) return false; 
    
  for (ll i = 5; i * i <= n; i += 6) 
  if (n % i == 0 || n % (i + 2) == 0) 
    return false; 
    
  return true; 
} 
    
  vector<int> pr, lp(N);
  void sieve() {
    for (int i = 2; i < N; i++) {
      if (lp[i] == 0) {
        pr.push_back(i);
        lp[i] = i;
      }
      for (auto p : pr) {
        if (i * p >= N) break;
        lp[i * p] = p;
        if (lp[i] == p) break;
      }
    }
  }

bool isPrime(int n) {
  return lp[n] == n;
}
