int dist[N][N],n;
vector <pair<int,pii>> edges;

void FloydWarshall()
{

     for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
               dist[i][j]=1e18;

     for(auto x:edges)
          dist[x.S.F]=dist[x.S.S], dist[x.S.S]=dist[x.S.F];

     for(int k=1;k<=n;k++)
          for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
                    dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}
