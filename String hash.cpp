int mod = 1e9 + 7, p1 = 31, p2 = 53;
int p1_pow[N], p2_pow[N], p1_inv[N], p2_inv[N];
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

void init()
{
     p1_pow[1] = 1;
     p2_pow[1] = 1;
     for (int i = 2; i < N; i++)
     {
          p1_pow[i] = mul(p1_pow[i - 1], p1);
          p2_pow[i] = mul(p2_pow[i - 1], p2);
     }
     for (int i = 1; i < N; i++)
     {
          p1_inv[i] = inv(p1_pow[i]);
          p2_inv[i] = inv(p2_pow[i]);
     }
}

struct Hash
{
     int n;
     vector <pii> v;

     void compute(string s)
     {
          int n = s.size();
          v.resize(n + 1, {0, 0});

          for (int i = 0; i < n; i++)
          {
               v[i + 1].F = (v[i].F + (s[i] - 'a' + 1) * p1_pow[i + 1]) % mod;
               v[i + 1].S = (v[i].S + (s[i] - 'a' + 1) * p2_pow[i + 1]) % mod;
          }
     }
     pii get(int l, int r)
     {
          pii h;
          h.F = mul(sub(v[r].F, v[l - 1].F), p1_inv[l]);
          h.S = mul(sub(v[r].S, v[l - 1].S), p2_inv[l]);
          return h;
     }

};

inline pii add_hash(pii hash1, pii hash2, int l) // l is length of hash1
{
     pii hash;
     hash.F = add(hash1.F, mul(hash2.F, p1_pow[l + 1]));
     hash.S = add(hash1.S, mul(hash2.S, p2_pow[l + 1]));
     return hash;
}
