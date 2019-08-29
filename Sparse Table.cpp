#include <bits/stdc++.h>
using namespace std;
 
const int N = 1<<20;
const int LOG = 21;
 
int rmq[N][LOG];
int arr[N],n;
 
void preprocess(int *a, int n) 
{
     int i,j;
     for(i=1;i<=n;i++) 
          rmq[i][0]=a[i];
     
     for(j=1;(1<<j)<=n;j++) 
          for(i=1;i+(1<<j)-1<=n;i++) 
               rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
 
int query(int a, int b) 
{
     int k=log2(b-a+1);
     return min(rmq[a][k],rmq[b-(1<<k)+1][k]);
}
 
int main() 
{
     n=5;
     arr[1]=3;
     arr[2]=5;
     arr[3]=1;
     arr[4]=5;
     arr[5]=2;
     preprocess(arr,5);
     cout<<query(1,5)<<endl<<query(1,2)<<endl<<query(4,5)<<endl;

     return 0;
}
