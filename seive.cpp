int is_prime[N];
vector <int> prime;

void seive()
{
     for(int i=0;i<N;i++) is_prime[i]=i;
     for(int i=2;i<N;i+=2) is_prime[i]=2;

     for(int i=3;i*i<N;i+=2)
     {
          if(is_prime[i]==i)
          {
               for(int j=i;j<N;j+=i)
               {
                    is_prime[j]=i;
               }
          }
     }

     for(int i=2;i<N;i++)
          if(is_prime[i]==i) prime.push_back(i);

}
