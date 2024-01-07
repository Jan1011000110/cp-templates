#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  
	int t = rand(1, 1);
	cout << t << endl;
	while (t--) {
		int n = rand(5, 10);
		int m = rand(0, 2 * n);
		cout << n << " ";
		cout << m << endl;
		
		map<pair<int,int>, int> edges;
		for (int i = 0; i < m; i++) {
			while (1) {
				int u = rand(0, n - 1), v = rand(0, n - 1);
				
				if (edges[{u, v}] || edges[{v, u}] || u == v) continue;
				cout << u << " " << v << endl;
				edges[{u, v}] = 1;
				break;
			}
		}
	}
 
}







