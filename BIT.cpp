int bit[N];
void update(int idx, int val)
{
     for (; idx <= n; idx = idx | (idx + 1))
          bit[idx] += val;
}
int pref(int r)
{
     int ret = 0;
     for (; r > 0; r = (r & (r + 1)) - 1)
          ret += bit[r];
     return ret;
}
int rsum(int l, int r) { return pref(r) - pref(l - 1); }
