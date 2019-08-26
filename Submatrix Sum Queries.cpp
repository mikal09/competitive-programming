const int N = 1005;
int a[N][N],aux[N][N],n,m;

void precompute()
{
     for (int i = 1; i <= m; i++)
          aux[1][i] = a[1][i];

     for (int i = 2; i <= n; i++)
          for (int j = 1; j <= m; j++)
               aux[i][j] = a[i][j] + aux[i - 1][j];

     for (int i = 1; i <= n; i++)
          for (int j = 2; j <= m; j++)
               aux[i][j] += aux[i][j - 1];

}
int query(int i1, int j1, int i2, int j2)
{
     int res1 = aux[i2][j2] + aux[i1 - 1][j1 - 1];
     int res2 = aux[i1 - 1][j2] + aux[i2][j1 - 1];

     return (res1 - res2);
}
