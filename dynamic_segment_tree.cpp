#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll N = 1e18;

struct Node
{
     Node *lp, *rp;
     ll sum;
};
inline ll eval(Node *p) { return p ? p->sum : 0LL; }

const ll bufSize = 1e7;
Node buf[bufSize];

Node *newNode()
{
     static auto ptr = buf;
     return ptr++;
}

ll getSum(Node *cur, ll l, ll r, ll x, ll y)
{
     if (!cur || x > r || y < l)
          return 0;

     if (x <= l && r <= y)
          return cur->sum;

     ll m = (l + r) / 2;

     return getSum(cur->lp, l, m, x, y) + getSum(cur->rp, m + 1, r, x, y);
}

void update(Node *&cur, ll l, ll r, ll pos, ll val)
{
     if (!cur)
          cur = newNode();
     if (l == r)
     {
          cur->sum = val;
     }
     else
     {
          ll m = (l + r) / 2;
          if (pos <= m)
          {
               update(cur->lp, l, m, pos, val);
          }
          else
          {
               update(cur->rp, m + 1, r, pos, val);
          }
          cur->sum = eval(cur->lp) + eval(cur->rp);
     }
}
Node *root;

int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

     return 0;
}
