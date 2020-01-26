// repetition of numbers are allowed
int knapSack()
{
     int dp[W + 1];
     memset(dp, 0, sizeof dp);
     int ans = 0;
     for (int i = 0; i <= W; i++)
          for (int j = 0; j < n; j++)
               if (wt[j] <= i)
                    dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
     return dp[W];
}

// repetition of numbers are not allowed
int knapSack()
{
     int K[n + 1][W + 1];
     for (int i = 0; i <= n; i++)
     {
          for (int w = 0; w <= W; w++)
          {
               if (i == 0 || w == 0)
                    K[i][w] = 0;
               else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],  K[i - 1][w]);
               else
                    K[i][w] = K[i - 1][w];
          }
     }
     return K[n][W];
}

// repetition of numbers are not allowed (space optimized)
int knapSack()
{
     int dp[W + 1];
     memset(dp, 0, sizeof(dp));

     for (int i = 0; i < n; i++)
          for (int j = W; j >= wt[i]; j--)
               dp[j] = max(dp[j] , val[i] + dp[j - wt[i]]);

     return dp[W];
}
