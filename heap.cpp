class Heap {
public:
     vector <int> v;

     Heap() {}

     Heap(vector <int> temp) {
          v = temp;
     }

     void insert(int x)
     {
          v.push_back(x);
          int last = sz(v);

          while (last > 1)
          {
               int par = last / 2;
               if (v[par - 1] < v[last - 1])
               {
                    swap(v[par - 1], v[last - 1]);
                    last = par;
               }
               else
                    break;
          }
     }
     int top()
     {
          if (v.size())
               return v[0];
          else
               return -1;
     }
     void removeTop()
     {
          if (!v.size())
               return;

          swap(v[0], v.back());
          v.pop_back();

          adjust(1);
     }

     void heapify()
     {
          for (int i = v.size() - 1; i >= 0; i--)
               adjust(i + 1);

          print(v);
     }

     void adjust(int cur)
     {
          while (2 * cur < v.size())
          {
               int c1 = 2 * cur, c2 = 2 * cur + 1;

               if (v[c1 - 1] < v[c2 - 1])
                    swap(c1, c2);

               if (v[cur - 1] < v[c1 - 1])
               {
                    swap(v[cur - 1], v[c1 - 1]);
                    cur = c1;
               }
               else
                    break;
          }
     }

};
