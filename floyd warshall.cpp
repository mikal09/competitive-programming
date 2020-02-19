int dst[405][405],n;
vector <pair<int,pii>> edges;

void FloydWarshall()
{

     for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
               if(i!=j) dst[i][j]=1e18;

     for(auto x:edges)
          dst[x.S.F][x.S.S]=x.F, dst[x.S.S][x.S.F]=x.F;

     for(int k=1;k<=n;k++)
          for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
                    dst[i][j]=min(dst[i][j], dst[i][k] + dst[k][j]);
}
