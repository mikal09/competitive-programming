int const N = 200005;
int const lgn = 20;

int P[N][lgn + 2], T[N], L[N], n;
vector <int> g[N];
void dfs(int i , int par)
{
     T[i] = par;
     L[i] = L[par] + 1;
     for (auto it : g[i])
          if (it != par)
               dfs(it, i);
}
void buildsparsetable()
{
     memset(P, -1, sizeof P);
     for (int i = 1; i <= n; i++)
          P[i][0] = T[i];

     for (int j = 1; j <= lgn; j++)
          for (int i = 1; i <= n; i++)
               if (P[i][j - 1] != -1)
                    P[i][j] = P[P[i][j - 1]][j - 1];
}
int lca(int a, int b)
{
     if (L[a] < L[b])
          swap(a, b);

     int jump = L[a] - L[b];
     for (int i = lgn; i >= 0; i--)
          if ((1 << i)&jump)
               a = P[a][i];

     if (a == b)
          return a;

     for (int i = lgn; i >= 0; i--)
          if (P[a][i] != -1 and P[b][i] != -1 and P[a][i] != P[b][i])
               a = P[a][i], b = P[b][i];

     return T[a];
}
int dist(int a, int b)
{
     int lc = lca(a, b);
     return L[a] - L[lc] + L[b] - L[lc];
}
void init()
{
     cin >> n;
     for (int i = 1; i < n; i++)
     {
          int x, y; cin >> x >> y;
          g[x].pb(y);
          g[y].pb(x);
     }

     dfs(1, 0);
     buildsparsetable();
}
