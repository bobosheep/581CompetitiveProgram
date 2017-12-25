#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tp;
int n, m;
ll ans;
priority_queue<tp, vector<tp >, greater<tp > > edge;

struct disjointset
{
    vector<int> parent, heigh;
    void init()
    {
        parent.clear();
        heigh.clear();
        for(int i = 0 ; i < n ; i++)
            parent.push_back(i), heigh.push_back(0);
    }
    int findp(int x)
    {
        return x == parent[x] ? x : findp(parent[x]);
    }
    void unionset(int x, int y)
    {
        ll fx = findp(x), fy = findp(y);
        if(fx == fy) return ;
        else
        {
            if(heigh[fx] > heigh[fy])
                parent[fy] = fx;
            else if(heigh[fx] < heigh[fy])
                parent[fx] = fy;
            else
            {
                parent[fy] = fx;
                heigh[fx]++;
            }
        }
    }
};

disjointset ds;

void init()
{
    ds.init();
    ans = 0;
    for(int i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        edge.push(make_tuple(w, u, v));
    }
}

void sol()
{
    while(!edge.empty())
    {
        int u, v, w;
        tie(w, u, v) = edge.top();
        edge.pop();
        if(ds.findp(u) != ds.findp(v))
        {
            ans += w;
            ds.unionset(u, v);
        }
    }
    cout << ans << endl;
}

int main()
{
    int ncase;
    cin >> ncase;

    while(ncase--)
    {
        cin >> n >> m;
        init();
        sol();
    }


    return 0;
}
