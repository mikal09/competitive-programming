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

// The formula basically says that the value of Φ(n) is equal to n multiplied by-product of (1 – 1/p) for all prime factors p of n. 
//      For example value of Φ(6) = 6 * (1-1/2) * (1 – 1/3) = 2.
