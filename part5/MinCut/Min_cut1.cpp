#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define oo 1e7+7
#define M 1005

ll flow[M][M];
ll n, m;
bool comb[M];
ll cut, ans;

void c(ll &s, ll &t)
{
    bool visit[M];
    ll w[M];
    memset(visit, 0, sizeof(visit));
    memset(w, 0, sizeof(w));
    int tmp = M - 1;
    for(int i = 0 ; i < n ; i++)
    {
        int mv = -oo;
        for(int j = 0 ; j < n ; j++)
        {
            if(!visit[j] && !comb[j] && mv < w[j] )
            {
                mv = w[j];
                tmp = j;
            }
        }
        if(t == tmp)
        {
            cut = w[t];
            return;
        }
        visit[tmp] = true ;
        s = t;
        t = tmp;
        for(int j = 0 ; j < n ; j++)
        {
            if(!visit[j] && !comb[j])
                w[j] += flow[t][j];
        }
    }
    cut = w[t];
}

void mincut()
{
    ll s, t;
    for(int  i = 0 ; i < n-1 ; i++)
    {
        s = t = -1;
        c(s, t);
        comb[t] = true;
        ans = min(ans, cut);
        for(int j = 0 ; j < n ; j++)
        {
            flow[s][j] += flow[t][j];
            flow[j][s] += flow[j][t];
        }
    }
}

void init()
{
    cut = ans = oo;
    memset(flow, 0, sizeof(flow));
    memset(comb, 0, sizeof(comb));

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        flow[u][v] = w;
        flow[v][u] = w;
    }

}

void sol()
{
    mincut();
    cout << ans << endl;

}

int main()
{
    //freopen("min_cut.in", "r", stdin);
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();
    }


    return 0;
}
