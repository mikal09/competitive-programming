
int timer,n,l;
vector<int> v[N],up[N],tin,tout;

void dfs(int i, int p)
{
    tin[i]=++timer;
    up[i][0]=p;

    for (int j=1; j<=l; j++)
        up[i][j] = up[up[i][j-1]][j-1];

    for(int x:v[i]) 
    {
        if(x!=p) dfs(x, i);
    }

    tout[i]=++timer;
}

bool is_ancestor(int u, int v)
{
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}

int lca(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for (int i=l; i>=0; i--) 
    {
        if(!is_ancestor(up[u][i],v)) u=up[u][i];
    }
    return up[u][0];
}

void build_lca(int root) 
{
    tin.resize(n+1);
    tout.resize(n+1);
    timer=0;
    l=ceil(log2(n+1));
    for(int i=0;i<=n;i++) up[i].resize(l+1);
    dfs(root, root);
}
