// https://codeforces.com/contest/609/problem/E

/*

  "With age, comes wisdom. With travel, comes understanding.
   Remember that happiness is a way of travel – not a destination"

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 2e5 + 5;
const int LN = 18;
int n , m;
int a , b , c;
vector < pair < int , int > > v[N];
int dp[LN][N];
int mx[LN][N];
pair < pair < int , int > , pair < int , int > > edges[N];
int parent[N];
long long sum = 0;
int depth[N];
long long ans[N];
int find(int node) {
     if (parent[node] == node) {
          return node;
     }
     return parent[node] = find(parent[node]);
}
bool join(int a , int b) {
     if (find(a) == find(b)) {
          return 0;
     }
     parent[find(a)] = find(b);
     return 1;
}
void dfs(int node , int parent) {
     dp[0][node] = parent;
     for (auto it : v[node]) {
          if (it.F != parent) {
               depth[it.F] = depth[node] + 1;
               mx[0][it.F] = it.second;
               dfs(it.F , node);
          }
     }
}
int lca(int a , int b) {
     if (depth[a] < depth[b]) {
          swap(a , b);
     }
     int dif = depth[a] - depth[b];
     int val = 0;
     for (int i = 0 ; i < LN ; ++i) {
          if (dif & (1 << i)) {
               val = max(val , mx[i][a]);
               a = dp[i][a];
          }
     }
     if (a != b) {
          for (int i = LN - 1 ; i >= 0 ; --i) {
               if (dp[i][a] != dp[i][b]) {
                    val = max(val , max(mx[i][a] , mx[i][b]));
                    a = dp[i][a];
                    b = dp[i][b];
               }
          }
          val = max(val , max(mx[0][a] , mx[0][b]));
     }
     return val;
}
void solve()
{
     cin >> n >> m;
     for (int i = 1 ; i <= m ; ++i) {
          cin >> a >> b >> c;
          edges[i] = {{c , i} , {a , b}};
     }
     for (int i = 1 ; i <= n ; ++i) {
          parent[i] = i;
     }
     sort(edges + 1 , edges + 1 + m);
     for (int i = 1 ; i <= m ; ++i) {
          if (join(edges[i].S.F , edges[i].S.S)) {
               sum += edges[i].F.F;
               v[edges[i].S.F].pb({edges[i].S.S , edges[i].F.F});
               v[edges[i].S.S].pb({edges[i].S.F , edges[i].F.F});
          }
     }
     mx[0][1] = 0;
     depth[1] = 0;
     dfs(1 , 0);
     for (int i = 1 ; i < LN ; ++i) {
          for (int j = 1 ; j <= n ; ++j) {
               dp[i][j] = dp[i - 1][dp[i - 1][j]];
               mx[i][j] = max(mx[i - 1][j] , mx[i - 1][dp[i - 1][j]]);
          }
     }
     for (int i = 1 ; i <= m ; ++i) {
          ans[edges[i].F.S] = sum - lca(edges[i].S.F , edges[i].S.S) + edges[i].F.F;
     }
     for (int i = 1 ; i <= m ; ++i) {
          cout << ans[i] << endl;
     }
}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif

     cout << setprecision(9) << fixed;
     clock_t z = clock();
     solve();
     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

     return 0;
}
