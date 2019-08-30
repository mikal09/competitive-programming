struct info
{
     int x;
     info () : x(0) {};
};
struct SegTree
{
     int N;
     vector<info> st;
     vector<int> lazy;

     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
          lazy.assign(4 * N + 5, 0);
     }

     void merge(info &cur, info &l, info &r) 
     {
          cur.x = l.x + r.x;
     }
     
     void propagate(int node, int L, int R)
     {
          st[node].x += lazy[node]*(R-L+1);
          if(L!=R) 
          {
               lazy[node*2] += lazy[node]; 
               lazy[node*2+1] += lazy[node];
          }
          lazy[node] = 0;
     }

     void Build(int node, int L, int R)
     {
          if(L==R)
          {
               st[node].x = 0;
               return;
          }
          int M=(L + R)/2;
          Build(node*2, L, M);
          Build(node*2 + 1, M + 1, R);
          merge(st[node], st[node*2], st[node*2+1]);
     }

     info Query(int node, int L, int R, int i, int j)
     {
          if(lazy[node])
               propagate(node, L, R);
          if(j<L || i>R)
               return info();
          if(i<=L && R<=j)
               return st[node];

          int M = (L + R)/2;
          info left=Query(node*2, L, M, i, j);
          info right=Query(node*2 + 1, M + 1, R, i, j);
          info cur;
          merge(cur, left, right);
          return cur;
     }   

     void Update(int node, int L, int R, int i, int j, int val)
     {
          if(lazy[node])
               propagate(node, L, R);
          if(j<L || i>R)
               return;

          if(i<=L && R<=j)
          {
               lazy[node]+= val;
               propagate(node, L, R);
               return;
          }
          int M = (L + R)/2;
          Update(node*2, L, M, i, j, val);
          Update(node*2 + 1, M + 1, R, i, j, val);
          merge(st[node], st[node*2], st[node*2 + 1]);
     }

     info query(int l, int r) { return Query(1, 1, N, l, r); }

     void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }

     void build() { Build(1, 1, N); }

};
