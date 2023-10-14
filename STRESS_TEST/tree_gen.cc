/*
    ID: janmata1
    PROG: ride
    LANG: C++17
*/
 
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
#define ld long double;
//#define int long long
 
#define lwb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
 
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
#define fi first
#define se second
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define ii pair<ll,ll> 
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define sz(x) (ll)size(x)

const ll N = 2e5+5, INF = 1e18, MOD = 1e9+7;

struct DSU{
    vector<int> v;
    DSU(int n){v.assign(n, -1);}
    int get(int x){return v[x] < 0 ? x : v[x] = get(v[x]);}
    void unite(int x, int y){
        x = get(x); y = get(y);
        if(x == y) return;
        if(v[x] > v[y]) swap(x, y);
        v[x] += v[y]; v[y] = x;
    }
    bool same(int x, int y){return (get(x) == get(y));}
};
 
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

mt19937 gen(time(0));

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    //int n = rand(2, 8);
    
	int n = rand(2, 8), m = n - 1, k = rand(1, 1000);
  for (int i = 0; i < n; i++) {
    cout << rand(0, k) << " ";
  }
  cout << endl;
	vector<vector<int>> adj(n + 1);
	DSU UF(n + 1);
	for(int i = 0; i < n - 1; i++){
		int x = gen() % n;
		int y = gen() % n;
		while(UF.same(x, y)) y = gen() % n;
    if (x < y) swap(x, y);
		adj[x].push_back(y); 
		
		UF.unite(x, y);
	}
  
  map<pair<int,int>, int> used;
  cout << n << " " << m << endl;
	//cout << n << endl;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<sz(adj[i]); j++) {
      cout << i << " " << adj[i][j] << endl;
			//cout << i << " " << adj[i][j] << endl;
		}
	}    
}
