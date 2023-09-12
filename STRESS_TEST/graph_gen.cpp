#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr <<__func__<<":"<<" [" << #x << "] = ["; _print(x); /*cerr << "\e[39m" << endl;*/
#else
#define dbg(x...)
#endif


#define ll long long
#define ld long double
#define int long long


#define fi first
#define se second
#define pb push_back
#define ii pair<ll,ll>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (ll)x.size()
#define endl '\n'

const ll N = 2e5+5, INF = 1e18, MOD = 1e9+7;


int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
//mt19937 gen(time(0));

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







