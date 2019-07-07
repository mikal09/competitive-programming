#ifdef ONLINE_JUDGE

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T> using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

namespace mapOp 
{
    const int tmp = chrono::high_resolution_clock::now().time_since_epoch().count();

    template<class T> struct hsh 
    {
        size_t operator()(const T& x) const 
        { 
            return hash<T>{}(x)^tmp;
        }
    };

    template<class a, class b> using um = gp_hash_table<a,b,hsh<a>>;

    template<class a, class b> b get(um<a,b>& u, a x) 
    {
        if (u.find(x) == u.end()) return 0;
        return u[x];
    }
}
using namespace mapOp;

#else

#define um unordered_map
template<class a, class b> b get(unordered_map<a,b>& u, a x) {
    if (u.find(x) == u.end()) return 0;
    return u[x];
}
#endif

um<int,int> mp;
