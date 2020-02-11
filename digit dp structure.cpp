// find solution from 0 to N.Make required changes according to the probelm;

int dp(int pos, int free)
{
     if (pos == n)
          return 1;

     int &ans = cache[pos][free];
     if (ans != -1)
          return ans;

     ans = 0;
     if (!free)
     {
          for (int i = 0; i < s[pos] - '0'; i++)
               ans += dp(pos, 1);

          ans += dp(pos + 1, 0);
     }
     else
     {
          for (int i = 0; i < 10; i++)
               ans += dp(pos + 1, 1);
     }

     return ans;
}
