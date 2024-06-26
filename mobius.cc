vector<int> pr, lp(N), mu(N);
void sieve() {
  mu[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.emplace_back(i);
      mu[i] = -1;
    }
    for (auto p : pr) {
      if (i * p >= N) break;
      lp[i * p] = p;
      mu[i * p] = -mu[i];
      if (lp[i] == p) {
        mu[i * p] = 0;
        break;
      }
    }
  }
}