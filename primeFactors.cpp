vector<int> primeFactors(int n)
{
     vector<int> vec;
     while (n % 2 == 0)
          vec.pb(2), n = n / 2;

     for (int i = 3; i * i <= n; i = i + 2)
          while (n % i == 0)
               vec.pb(i), n = n / i;

     if (n > 2)
          vec.pb(n);

     return vec;
}
