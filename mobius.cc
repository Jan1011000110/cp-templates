vector<int> pr, lp(N), mu(N);
void sieve() {
  mu[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.emplace_back(i);
      mu[i] = -1;
    }
    for (int j = 0; i * pr[j] < N; ++j) {
      lp[i * pr[j]] = pr[j];
      mu[i * pr[j]] = -mu[i];
      if (pr[j] == lp[i]) {
        mu[i * pr[j]] = 0;
        break;
      }
    }
  }
}