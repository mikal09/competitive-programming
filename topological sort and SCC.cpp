vi g[N], gr[N], order, tps, sc;
int vis[N];

void dfs(int i)
{
     vis[i] = 1;
     for (auto x : g[i])
          if (!vis[x])
               dfs(x);
     order.pb(i);
}
void dfs1(int i)
{
     vis[i] = 1;
     sc.pb(i);
     for (auto x : gr[i])
          if (!vis[x])
               dfs1(x);
}
bool cycle()
{
     for (int i = 1; i <= n; i++)
          if (!vis[i])
               dfs(i);

     // if there is no loop in the graph then tsp store topological sort of the graph
     tps = order;
     reverse(all(tps));
     memset(vis, 0, sizeof vis);
     int mx = 0;

     while (sz(order)) // this part is for strongly connected component
     {
          sc.clear();
          dfs1(order.back());
          while (sz(order) && vis[order.back()])
               order.pop_back();

          mx = max(mx, sz(sc));
     }
     // if there is no self loops
     return (mx > 1);
}
