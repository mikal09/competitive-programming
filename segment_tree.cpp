struct data
{
     int x;
     data () : x(0) {};
};
struct SegTree
{
     int N;
     vector<data> st;

     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
     }

     void merge(data &cur, data &l, data &r) 
     {
          cur.x = l.x + r.x; 
     }

     void Build(int node, int L, int R)
     {
          if(L==R)
          {
               st[node].x = a[L];
               return;
          }
          int M=(L + R)/2;
          Build(node*2, L, M);
          Build(node*2 + 1, M + 1, R);
          merge(st[node], st[node*2], st[node*2+1]);
     }

     data Query(int node, int L, int R, int i, int j)
     {
          if(j<L || i>R)
               return data();
          if(i<=L && R<=j)
               return st[node];
          int M = (L + R)/2;
          data left=Query(node*2, L, M, i, j);
          data right=Query(node*2 + 1, M + 1, R, i, j);
          data cur;
          merge(cur, left, right);
          return cur;
     }   

     void Update(int node, int L, int R, int pos, int val)
     {
          if(L == R)
          {
               st[node].x += val;
               return;
          }
          int M = (L + R)/2;
          if(pos <= M)
               Update(node*2, L, M, pos, val);
          else
               Update(node*2 + 1, M + 1, R, pos, val);

          merge(st[node], st[node*2], st[node*2 + 1]);
     }

     data query(int l, int r) { return Query(1, 1, N, l, r); }

     void update(int pos, int val) { Update(1, 1, N, pos, val); }

     void build() { Build(1,1,N); }

};
