int discreteLog(int a, int b)
{
     a %= mod, b %= mod;
     if (b == 1)
          return 0;
     int cnt = 0;
     long long t = 1;
     for (int curg = __gcd(a, mod); curg != 1; curg = __gcd(a, mod))
     {
          if (b % curg)
               return -1;
          b /= curg, mod /= curg, t = (t * a / curg) % mod;
          cnt++;
          if (b == t)
               return cnt;
     }

     gp_hash_table<int, int> hash;
     int mid = ((int)sqrt(1.0 * mod) + 1);
     long long base = b;
     for (int i = 0; i < mid; i++)
     {
          hash[base] = i;
          base = base * a % mod;
     }

     base = powr(a, mid);
     long long cur = t;
     for (int i = 1; i <= mid + 1; i++)
     {
          cur = cur * base % mod;
          auto it = hash.find(cur);
          if (it != hash.end())
               return i * mid - it->second + cnt;
     }
}
