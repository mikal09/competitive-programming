vpi v[N];
vi dis;

void dijkstra(int r, int n) 
{
     for(int i=0;i<=n;i++) v[i].clear();

     priority_queue<pii, vector<pii>, greater<pii> > Q;  
     dis.assign(n+1,1e18);
     dis[r] = 0;
     Q.push({0,r});

     while(!Q.empty())
     {
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u])
        {
            int v = c.first;
            int w = c.second;
            if(dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                Q.push({dis[v],v});
            }
        }
     }

}
