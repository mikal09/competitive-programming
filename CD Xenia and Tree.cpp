/*

“ Remember, Hope is a good thing,
  maybe the best of things,
  and no good thing ever dies.”

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int             long long int
#define ld              long double
#define F               first
#define S               second
#define pb              push_back
#define si              set <int>
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define vpp             vector <pair<int, pii>>
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define Print(a,x,y)    for (int i=x; i<y; i++) cout<< a[i]<< " "; cout << endl

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

const int N = 100005;
const int LOGN = 20;
int i, j, n, q, nn;
int dp[LOGN][N], par[N], sub[N], level[N], ans[N];
set <int> g[N];

void dfs0(int u)
{
     for (auto x : g[u])
          if (x != dp[0][u])
          {
               dp[0][x] = u;
               level[x] = level[u] + 1;
               dfs0(x);
          }
}

void dfs1(int u, int p)
{
     sub[u] = 1;
     nn++;
     for (auto x : g[u])
          if (x != p)
          {
               dfs1(x, u);
               sub[u] += sub[x];
          }
}

int dfs2(int u, int p)
{
     for (auto x : g[u])
          if (x != p && sub[x] > nn / 2)
               return dfs2(x, u);
     return u;
}

void decompose(int root, int p)
{
     nn = 0;
     dfs1(root, root);
     int centroid = dfs2(root, root);

     if (p == -1)
          p = centroid;

     par[centroid] = p;

     for (auto x : g[centroid])
     {
          g[x].erase(centroid);
          decompose(x, centroid);
     }
     g[centroid].clear();
}

void preprocess()
{
     level[0] = 0;
     dp[0][0] = 0;
     dfs0(0);
     for (int i = 1; i < LOGN; i++)
          for (int j = 0; j < n; j++)
               dp[i][j] = dp[i - 1][dp[i - 1][j]];
}

int lca(int a, int b)
{
     if (level[a] > level[b])
          swap(a, b);

     int d = level[b] - level[a];

     for (int i = 0; i < LOGN; i++)
          if (d & (1 << i))
               b = dp[i][b];

     if (a == b)
          return a;

     for (int i = LOGN - 1; i >= 0; i--)
          if (dp[i][a] != dp[i][b])
               a = dp[i][a], b = dp[i][b];

     return dp[0][a];
}

int dist(int u, int v)
{
     return level[u] + level[v] - 2 * level[lca(u, v)];
}

void update(int u)
{
     int x = u;
     while (1)
     {
          ans[x] = min(ans[x], dist(x, u));
          if (x == par[x])
               break;
          x = par[x];
     }
}

int query(int u)
{
     int x = u;
     int ret = 1e9;
     while (1)
     {
          ret = min(ret, dist(u, x) + ans[x]);
          if (x == par[x])
               break;
          x = par[x];
     }
     return ret;
}

void solve()
{
     cin >> n >> q;
     for (i = 0; i < n - 1; i++)
     {
          int x, y; cin >> x >> y;
          g[x - 1].insert(y - 1);
          g[y - 1].insert(x - 1);
     }

     preprocess();
     decompose(0, -1);

     for (int i = 0; i < n; i++)
          ans[i] = 1e9;

     update(0);

     while (q--)
     {
          int t, v;
          cin >> t >> v;
          if (t == 1)
               update(v - 1);
          else
               cout << query(v - 1) << endl;
     }


}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif

     solve();

     return 0;
}
