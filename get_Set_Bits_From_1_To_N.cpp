vector <int> getSetBitsFromOneToN(int N)
{
	int two = 2, ans = 0;
	int n = N;
	vector <int> v;
	while (n) 
	{
		int x = (N / two) * (two >> 1LL);
		if ((N & (two - 1)) > (two >> 1LL) - 1)
			x += (N & (two - 1)) - (two >> 1LL) + 1;
		v.pb(x);
		two <<= 1;
		n >>= 1;
	}
	return v;
}
