int findProductSum(vector<int> A)
{
	int n = a.size();
	if (n == 1)
		return A[0];

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + A[i];

	int sum_sqr = sum * sum;
	int indv_sqr_sum = 0;
	
	for (int i = 0; i < n; i++)
		indv_sqr_sum += A[i] * A[i];

	return (sum_sqr - indv_sqr_sum) / 2;
}
