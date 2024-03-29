int modInverse(int a, int m) 
{ 
    if (m == 1) return 0;
    int m0 = m, y = 0, x = 1; 

    while(a > 1) 
    {  
        int q = a/m, t = m; 
        m = a%m, a = t; 
        t = y; 
        y = x - q*y; 
        x = t; 
    }  
    if(x < 0) x += m0; 

    return x; 
} 

int gcdExtended(int a, int b, int* x, int* y)
{
     if (a == 0)
     {
          *x = 0, *y = 1;
          return b;
     }
     
     int x1, y1;
     int gcd = gcdExtended(b % a, a, &x1, &y1);

     *x = y1 - (b / a) * x1;
     *y = x1;

     return gcd;
}

void modInverse(int a, int m)
{
     int x, y;
     int g = gcdExtended(a, m, &x, &y);
     if (g != 1)
          cout << "Inverse doesn't exist";
     else
     {
          int res = (x % m + m) % m;
          cout << "Modular multiplicative inverse is " << res;
     }
}
