int node1, node2, dia;
void dfs_0(int i, int p, int dis)
{
     if (sz(v[i]) == 1 && dis > dia)
          dia = dis, node1 = i;

     for (auto x : v[i])
          if (x != p)
               dfs_0(x, i, dis + 1);
}
void dfs_1(int i, int p, int dis)
{
     if (sz(v[i]) == 1 && dis > dia)
          dia = dis, node2 = i;

     for (auto x : v[i])
          if (x != p)
               dfs_1(x, i, dis + 1);
}
void diameter()
{
     dfs_0(1, 0, 0);
     dia = 0;
     dfs_1(node1, 0, 0);
}
