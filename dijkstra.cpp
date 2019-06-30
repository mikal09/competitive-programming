vpi v[N];
vi dis;

void Dijkstra(int r, int n) 
{
     priority_queue<pii, vector<pii>, greater<pii> > Q;  
     dis.assign(n+1,1e18);
     dis[r] = 0;
     Q.push({0,r});

     while(!Q.empty())
     {
        int u = Q.top().second;
        Q.pop();
        for(auto &c : v[u])
        {
            int x = c.first;
            int w = c.second;
            if(dis[x] > dis[u]+w)
            {
                dis[x] = dis[u]+w;
                Q.push({dis[x],x});
            }
        }
     }

}
