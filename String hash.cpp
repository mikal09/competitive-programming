long long compute_hash(string const& s) 
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) 
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}




set <int> ans;
void compute_hash(string s)
{
     const int p = 31, p1 = 53;
     const int m = 1e9 + 9;
     int hash_value = 0, hash1_value = 0;
     int p_pow = 1, p1_pow = 1;

     for (char c : s)
     {
          hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
          p_pow = (p_pow * p) % m;
          hash1_value = (h1ash_value + (c - 'a' + 1) * p1_pow) % m;
          p1_pow = (p1_pow * p1) % m;

          ans.insert({hash_value, hash1_value});

     }
}
