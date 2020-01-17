int vis[N][N];
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, +1, -1};

void bfs(int x, int y, int n, int m)
{
     queue<pair<int, int> > q;
     q.push({x, y});
     vis[x][y]=1;
     
     while(!q.empty())
     {
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int dir=0;dir<4;dir++)
          {
               int x1=x+dx[dir];
               int y1=y+dy[dir];
               if(x1<1 || y1<1 || x1>n || y1>m) continue;

               if(!vis[x1][y1])
               {
                    vis[x1][y1]=1;
                    q.push({x1, y1});
               }
          }
     }
}
