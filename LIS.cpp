int LIS(vector<int>& v)
{
     if (v.size() == 0)
          return 0;

     vector<int> tail(v.size(), 0);
     int length = 1;

     tail[0] = v[0];
     for (int i = 1; i < v.size(); i++)
     {
          if (v[i] >= tail[length - 1])
               tail[length++] = v[i];
          else
          {
               auto it = find(tail.begin(), tail.begin() + length, v[i]);
               if (it != tail.begin() + length)
                    continue;
               it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
               *it = v[i];
          }
     }
     
     return length;
}
