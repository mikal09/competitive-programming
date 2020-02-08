// generate pythagoras_triplet

vector <pair<pii, int>> v, v1;
void pythagoras_triplet()
{
	for (int i = 1; i <= 200000; i++)
		for (int j = i + 1; j <= 200000; j++)
		{
			if (j % i == 0 && i != 1)
				continue ;
			int a = j * j - i * i;
			int b = 2 * i * j;
			int c = i * i + j * j;
			if (a > b)
				swap(a, b);
			if (c <= 200000)
				v1.pb({{a, b}, c});
			else
				break;
		}

	for (auto x : v1)
	{
		int a = x.F.F, b = x.F.S, c = x.S, k = 1;
		while (k * c <= 200000)
		{
			v.pb({{k * a, k * b}, k * c});
			k++;
		}
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

}
