#include <bits/stdc++.h>
 
using namespace std;
 
#define DIM 50007
 
#define INF 1000000007
 
long long n;
 
struct Tnode{ long long sum, maxprefix, maxsuffix, maxsum; } T[4*DIM];
long long a[DIM];
 
Tnode combine(Tnode &node1, Tnode &node2) {
    Tnode resnode;
    resnode.sum = node1.sum + node2.sum;
    resnode.maxprefix = max(node1.maxprefix, node1.sum + node2.maxprefix);
    resnode.maxsuffix = max(node1.maxsuffix + node2.sum, node2.maxsuffix);
    resnode.maxsum = max(  (node1.maxsuffix + node2.maxprefix), max(node1.maxsum , node2.maxsum));
 
    return resnode;
}
 
void BuildTree(int v, int tl, int tr) {
    if(tl==tr) {
        T[v] = { a[tl], a[tl], a[tl], a[tl] }; //відрізок з одного елемента
        return;
    }
 
    int tm = (tl+tr)/2;
    BuildTree(2*v+1, tl, tm);
    BuildTree(2*v+2, tm+1, tr);
 
    T[v] = combine(T[2*v+1] , T[2*v+2]);
}
 
void modify(int v, int tl, int tr, int x, int val) {
    if(x < tl || tr < x) return;
 
    if(tl==tr) {
        T[v] = { val, val, val, val };
        return;
    }
 
    int tm = (tl+tr)/2;
    modify(2*v+1, tl, tm, x, val);
    modify(2*v+2, tm+1, tr, x, val);
 
    T[v] = combine(T[2*v+1], T[2*v+2]);
}
 
Tnode getquery(int v, int tl, int tr, int L, int R) {
    if(R < tl || tr < L) return {0,-INF,-INF,-INF};
 
    if(L <= tl && tr <= R) {
        return T[v];
    }
 
    int tm = (tl+tr)/2;
    Tnode node1 = getquery(2*v+1, tl, tm, L, R);
    Tnode node2 = getquery(2*v+2, tm+1, tr, L, R);
 
    return combine(node1, node2);
}
 
int main() {
 
    scanf("%lld\n",&n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
 
    BuildTree(0,1,n);
 
    long long k,L,R,type;
    Tnode item;
 
    scanf("%lld",&k);
    for(int i = 1; i <= k; i++) {
        scanf("%lld %lld %lld", &type, &L, &R);
 
        if(type == 0) modify(0,1,n,L,R);
        else {
            item = getquery(0, 1, n, L, R);
            printf("%lld\n", item.maxsum);
        }
 
    }
 
 
    return 0;
}
