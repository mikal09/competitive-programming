const int M = 5;
struct mat_expo
{
     int m[M][M];

     mat_expo() { memset(m, 0, sizeof m); }

     void eye() { lop(i, 0, M) m[i][i] = 1; }

     mat_expo operator*(const mat_expo &a) const
     {
          mat_expo r;
          lop(i, 0, M) lop(j, 0, M) lop(k, 0, M)
          r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
          return r;
     }
};
mat_expo getans(mat_expo bb, int k)
{
     mat_expo aa;
     aa.eye();
     while (k > 0)
     {
          if (k & 1) aa = aa * bb;
          bb = bb * bb;
          k /= 2;
     }
     return aa;
}
