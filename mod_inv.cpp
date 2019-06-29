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
