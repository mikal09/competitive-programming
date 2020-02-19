int euler_totient(int num)
{
     int total = num;
     for (int i = 2; i * i <= num; i++)
     {
          if (num % i)
               continue;
          while (num % i == 0)
               num /= i;
          total -= total / i;
     }
     if (num > 1)
          total -= total / num;
     return total;
}
