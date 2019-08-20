int fact[N], mod = 1e9 + 7;
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
inline int powr(int a, int b) {
     int x = 1 % mod;
     while (b) {
          if (b & 1) x = mul(x, a);
          a = mul(a, a);
          b >>= 1;
     }
     return x;
}
inline int inv(int a) { return powr(a, mod - 2); }

void precompute()
{
     fact[0] = 1;
     for (int i = 1; i < N; i++)
          fact[i] = mul(fact[i - 1], i);
}
int nCr(int num, int den)
{
     int den1 = fact[den], den2 = fact[num - den];
     num = fact[num];
     den = mul(den1, den2);
     int ans = mul(num, inv(den));
     return ans;
}
