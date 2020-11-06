vector<int> g[N],art_point;
int n, t[N], t1[N], tim;
vector <pair<int,int>> edges;

// bridges
void bridges(int i, int p)
{
     t[i] = t1[i] = ++tim;

     for (auto x : g[i])
     {
          if (!t[x])
               bridges(x, i);
          if (x != p)
               t1[i] = min(t1[i], t1[x]);
     }
     for (auto x : g[i])
          if (t1[i] > t[x])
               edges.pb({i,x});
}

// articulation point
void articulation_point(int i, int p)
{
     t[i] = t1[i] = ++tim;

     for (auto x : g[i])
     {
          if (!t[x])
               articulation_point(x, i);
          if (x != p)
               t1[i] = min(t1[i], t1[x]);
     }
     for (auto x : g[i])
          if (t1[i] > t[x])
          {
               art_point.pb(x);
               break;
          }
}
