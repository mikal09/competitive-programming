vector <int> e; // push node1 before calling find_path
int node1, node2, done;
void find_path(int i = node1, int p = 0)
{
     if (i == node2)
     {
          done = 1;
          return ;
     }

     for (auto x : v[i])
          if (x != p && !done)
          {
               e.pb(x);
               find_path(x, i);
               if (done) return;
               e.pop_back();
          }
}
