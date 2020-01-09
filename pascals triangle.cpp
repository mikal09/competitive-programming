vector <int> nc[N];
void pascal()
{
	nc[0].pb(1);
	for (int i = 1; i < N; i++)
	{
		nc[i].pb(1);
		int s = nc[i - 1].size();
		for (int j = 0; j < s; j++)
		{
			if (j == s - 1)
				nc[i].pb(1);
			else
				nc[i].pb((nc[i - 1][j] + nc[i - 1][j + 1]) % mod);
		}
	}
}
