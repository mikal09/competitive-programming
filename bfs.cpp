int vis[N];
vector<int> v[N];

void bfs(int k)
{
     queue<int> q;
     q.push(k);
     ways[k]=1;
     vis[k]=1;
     while(!q.empty())
     {
          int node=q.front();
          q.pop();
          for(auto x:v[node])
          {
               if(!vis[x])
               {
                    vis[x]=1;
                    q.push(x);
               }
          }
     }
}
