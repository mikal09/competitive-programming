// finds solution from 0 to R. Make required changes according to the probelm;

int dp(int pos, int free)
{
     if (pos == n)
          return 1;

     int &ans = cache[pos][free];
     if (ans != -1)
          return ans;

     ans = 0;
     int lmt = (free ? 10 : s[pos] - '0');

     for (int i = 0; i < lmt; i++)
          ans += dp(pos + 1, 1);

     if (!free)
          ans += dp(pos + 1, 0);

     return ans;
}
