bool isSubsetSum()
{
     bool dp[n + 1][sum + 1];

     for (int i = 0; i <= n; i++)
          dp[i][0] = true;

     for (int i = 1; i <= sum; i++)
          dp[0][i] = false;

     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= sum; j++)
          {
               if (j < a[i - 1])
                    dp[i][j] = dp[i - 1][j];
               else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
          }

     return dp[n][sum];
}

// space optimized
bool isSubsetSum()
{
     bool dp[2][sum + 1];

     for (int i = 0; i <= n; i++)
          for (int j = 0; j <= sum; j++)
          {
               if (j == 0)
                    dp[i % 2][j] = true;
               else if (i == 0)
                    dp[i % 2][j] = false;
               else if (a[i - 1] <= j)
                    dp[i % 2][j] = dp[(i + 1) % 2][j - a[i - 1]] || dp[(i + 1) % 2][j];
               else
                    dp[i % 2][j] = dp[(i + 1) % 2][j];
          }

     return dp[n % 2][sum];
}
