int LCS(int i, int j)
{
	if (i == n || j == n)
		return 0;

	int &ans = cache[i][j];
	if (ans != -1)
		return ans;

	if (s1[i] == t1[j])
		ans = 1 + LCS(i + 1, j + 1);
	else
		ans = max(LCS(i + 1, j), LCS(i, j + 1));

	return ans;
}
