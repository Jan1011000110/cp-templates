#include <bits/stdc++.h>
using namespace std;
#define dbg(a) cerr << #a << " = " << a << endl;
#define N 1e9

void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  vector<int> pref_p(n + 1, 1), pref_s(n + 1);
  for (int i = 0; i < n; i++) {
    pref_p[i + 1] = pref_p[i] * a[i];
    pref_s[i + 1] = pref_s[i] + a[i];
  }
  
  auto range_p = [&](int l, int r) {
    return pref_p[r + 1]/pref_p[l];
  };
  
  auto range_s = [&](int l, int r) {
    return pref_s[r + 1]-pref_s[l];
  };
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans = max(ans, range_s(0, i - 1) + range_s(j + 1, n - 1) + range_p(i, j));
    }
  }
  cout << ans << endl;
}
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    test_case();
  }
  return 0;
}




