#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll > vpll;
#define M 5005
#define oo 10000007
#define v first
#define w second
ll n, m, q;
vpll path[M];
ll d[M];
bool ans;

void Bellmanford(int src, int dst)
{
    ll org;
    for(int i = 0 ; i < n ; i++)
    {
        d[i] = oo;
        //neg[src][i] = true;
    }
    d[src] = 0;
    for(int k = 0 ; k < n - 1 ; k++)    //n - 1
    {
        for(int i = 0 ; i < n ; i++)    //m
            for(int j = 0 ; j < path[i].size() ; j++)
                if(d[i] != oo)
                    if(d[i] + path[i][j].w < d[path[i][j].v])
                        d[path[i][j].v] = d[i] + path[i][j].w;

    }
    org = d[dst];
    for(int k = 0 ; k < 2 ; k++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < path[i].size() ; j++)
                if(d[i] != oo)
                    if(d[i] + path[i][j].w < d[path[i][j].v])
                    {
                        d[path[i][j].v] = d[i] + path[i][j].w;
                    }
            if(org > d[dst])
            {
                ans = false;
                break;
            }
        }
        if(!ans) break;
    }
}
void init()
{
    ans = true;
    for(int i = 0 ; i < M ; i++) path[i].clear();
    scanf("%lld%lld%lld", &n, &m, &q);
    for(int i = 0 ; i < m ; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        path[x].push_back(make_pair(y, w));
    }

}

void sol()
{
    bool visit[M];
    for(int i = 0 ; i < n ; i++)
        visit[i] = false;
    for(int i = 0 ; i < q ; i++)
    {
        int x, y;
        ans = true;


        scanf("%d%d", &x, &y);
        Bellmanford(x, y);
        if(ans && d[y] != oo)
        {
            printf("%lld\n", d[y]);
        }
        else printf("No\n");
    }
}



int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();
    }


    return 0;
}
