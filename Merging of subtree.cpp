
//https://codeforces.com/contest/600/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v[110101];
bool used[101010];
int col[101010];
int tot[101010];
map<int, int> counts[101010];
map<int, ll> colors[101010];
ll ans[101010];

void go(int cur)
{
     used[cur] = true;
     counts[cur][col[cur]]++;
     colors[cur][1] += col[cur];

     for (int to : v[cur])
     {
          if (used[to])
               continue;
          go(to);
          int f = cur;
          int t = to;

          if (counts[f].size() > counts[t].size())
               swap(f, t);

          for (auto p : counts[f])
          {
               int& siz = counts[t][p.first];
               if (siz)
                    colors[t][siz] -= p.first;

               siz += p.second;
               colors[t][siz] += p.first;

          }
          counts[f].clear();

          if (cur != t)
          {
               counts[cur].swap(counts[t]);
               colors[cur].swap(colors[t]);
          }
     }

     ans[cur] = colors[cur].rbegin()->second;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif
     int n;
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          cin >> col[i];
          tot[col[i]]++;
     }
     for (int i = 0; i < n - 1; i++)
     {
          int x, y;
          cin >> x >> y;
          --x; --y;
          v[x].push_back(y);
          v[y].push_back(x);
     }
     go(0);
     for (int i = 0; i < n; i++)
          cout << ans[i] << ' ';
     cout << endl;

     return 0;
}
