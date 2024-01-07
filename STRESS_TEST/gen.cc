#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
  return a + rand() % (b - a + 1);
}
//mt19937 gen(time(0));

int main(int argc, char* argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  
	int t = rand(1, 1);
	cout << t << endl;
	while (t--) {
		int n = rand(1, 10);
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      cout << rand(1, 3) << " ";
    }
    cout << endl;
	}
}







