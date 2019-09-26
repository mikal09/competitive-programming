struct DSU
{
     vector <int> uf, sz;

     void init(int n)
     {
          uf.resize(n + 1);
          sz.resize(n + 1);
          for (int i = 0; i <= n; i++)
               uf[i] = i, sz[i] = 1;
     }

     int root(int i)
     {
          while (uf[i] != i)
          {
               uf[i] = uf[uf[i]];
               i = uf[i];
          }
          return i;
     }

     void Union(int A, int B)
     {
          int root_A = root(A);
          int root_B = root(B);

          if (root_B == root_A)
               return ;

          if (sz[root_A] < sz[root_B ])
               swap(root_A, root_B);

          uf[root_B] = uf[root_A];
          sz[root_A] += sz[root_B];

     }

};
