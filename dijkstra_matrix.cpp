int const N = 25;
int n, m, dis[N][N];
int dx[4] = { -1, +1, 0, 0};
int dy[4] = {0, 0, +1, -1};

void dijkstra_matrix(int x, int y)
{
     priority_queue<pii, vector<pii>, greater<pii> > q;
     q.push({x, y});

     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++)
               dis[i][j] = 1e9;

     dis[x][y] = 0;

     while (!q.empty())
     {
          int x = q.top().first;
          int y = q.top().second;
          q.pop();

          for (int dir = 0; dir < 4; dir++)
          {
               int x1 = x + dx[dir];
               int y1 = y + dy[dir];
               if (x1 < 1 || y1 < 1 || x1 > n || y1 > m) continue;

               if (dis[x1][y1] > dis[x][y] + 1)
               {
                    dis[x1][y1] = dis[x][y] + 1;
                    q.push({x1, y1});
               }
          }
     }

}
