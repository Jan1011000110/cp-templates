vector<int> pr, lp(N), mobius(N);
void sieve() {
  mobius[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.emplace_back(i);
      mobius[i] = -1;
    }
    for (int j = 0; i * pr[j] < N; ++j) {
      lp[i * pr[j]] = pr[j];
      mobius[i * pr[j]] = -mobius[i];
      if (pr[j] == lp[i]) {
        mobius[i * pr[j]] = 0;
        break;
      }
    }
  }
}