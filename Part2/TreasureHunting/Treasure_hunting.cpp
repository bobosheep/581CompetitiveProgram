#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(a,b) for(int i=a;i<b;i++)
#define MAX 5005

int n, m, t, adj[MAX][MAX], go[MAX];
int ans;
vector<int> value, start;

void find_t(int x)
{
    if(!go[x]) return;
    ans = max(ans, value[x]);
    go[x] = 0;
    rep(0,n)
    {
        if(adj[x][i])
            find_t(i);
    }
}

void init()
{
    ans = 0;
    memset(adj, 0, sizeof(adj));
    value.clear();
    start.clear();
    rep(0, t)
    {
        int tmp;
        scanf("%d",&tmp);
        start.pb(tmp);
    }
    rep(0, n)
    {
        int tmp;
        scanf("%d",&tmp);
        value.pb(tmp);
    }
    rep(0, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x][y] = 1;
    }
}

void sol()
{
    rep(0, t)
    {
        memset(go, 1, sizeof(go));
        find_t(start[i]);
    }
    cout << ans << endl;
}

int main()
{
    while(cin >> n >> m >> t)
    {
        if(n == 0 && m == 0 && t == 0)
            break;
        init();
        sol();

    }

    return 0;
}
