#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll > vpll;
typedef tuple<ll, ll, ll > tlll;
#define M 10005
#define dst first
#define weight second
#define oo 10000007

vpll adjlist[M];
ll n, m, q;
ll dist[M], parent[M], w[M], ans;
priority_queue<pll, vector<pll >, greater<pll> > myset;

void Dij(int src)
{
    for(int i = 0 ; i < n ; i++)
        dist[i] = oo, parent[i] = i, w[i] = oo;
    dist[src] = 0;
    while(!myset.empty()) myset.pop();
    myset.push(make_pair(0, src));
    while(!myset.empty())
    {
        ll nextpoint;
        nextpoint = myset.top().second;
        myset.pop();
        for(auto i : adjlist[nextpoint])
        {
            if(dist[i.dst] > dist[nextpoint] + i.weight)
            {
                dist[i.dst] = dist[nextpoint] + i.weight;
                w[i.dst] = i.weight;
                myset.push(make_pair(dist[i.dst], i.dst));
                parent[i.dst] = nextpoint;
            }
            else if(dist[i.dst] == dist[nextpoint] + i.weight && i.weight < w[i.dst])
            {
                dist[i.dst] = dist[nextpoint] + i.weight;
                w[i.dst] = i.weight;
                myset.push(make_pair(dist[i.dst], i.dst));
                parent[i.dst] = nextpoint;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        //printf("point %d, parent is %lld, dist is %lld, parent dist is %lld\n", i, parent[i], dist[i], dist[parent[i]]);
        ans += dist[i] - dist[parent[i]];
    }

}

void init()
{
    ans = 0;
    for(int i = 0 ; i < M ; i++)
        adjlist[i].clear();

    for(int i = 0 ; i < m ; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adjlist[u].push_back(make_pair(v, w));
    }
}

void sol()
{
    for(int i = 0 ; i < q ; i++)
    {
        int src;
        scanf("%d", &src);
        ans = 0;
        Dij(src);
        printf("%lld\n", ans);
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        cin >> n >> m >> q;
        init();
        sol();
    }

    return 0 ;
}
