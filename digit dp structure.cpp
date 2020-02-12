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

// finds solution from L to R. Make required changes according to the probelm;

int dp(int pos, int bara, int chota)
{
     if (pos == n)
          return 1;

     int &ans = cache[pos][bara][chota];
     if (ans != -1)
          return ans;

     ans = 0;
     int st = (bara ? -1 : s[pos] - '0');
     int en = (chota ? 10 : s1[pos] - '0');

     for (int i = st + 1; i < en; i++)
          ans += dp(pos + 1, 1, 1);

     if (!bara)
          ans += dp(pos + 1, 0, (chota ? 1 : (st != en)));

     if (!chota and (bara or st != en))
          ans += dp(pos + 1, (bara ? 1 : (st != en)), 0);

     return ans;
}
