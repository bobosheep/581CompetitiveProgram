#include<bits/stdc++.h>
using namespace std;

#define oo 2147483647
typedef long long ll;
typedef pair<ll, ll> llp;
typedef vector<llp > llpv;

struct QQ
{
    ll des, risk, w;
};

vector<struct QQ > adjlis[30005];
ll dis[30005], risk[30005];
ll minrisk, n, m;
bool visit[30005];
priority_queue<llp, llpv, greater<llp> > myset;

void Dijktra_risk()
{

    for(int i = 0 ; i < 30005 ; i++)
    {
        risk[i] = oo;
        visit[i] = 0;
    }
    risk[0] = 0;
    myset.push({0, 0});
    while(!myset.empty())
    {
        ll tmp = myset.top().second;
        //cout << tmp << endl;
        myset.pop();
        if(visit[tmp]) continue;
        visit[tmp] = true;
        for(auto i : adjlis[tmp])
        {
            if(risk[i.des] > max(risk[tmp], i.risk))
            {
                risk[i.des] = max(risk[tmp], i.risk);
                myset.push({risk[i.des], i.des});
            }
        }
    }
}

void Dijktra_path()
{
    while(!myset.empty()) myset.pop();
    for(int i = 0 ; i < 30005 ; i++)
    {
        dis[i] = oo;
        visit[i] = 0;
    }
    dis[0] = 0;
    myset.push({0, 0});
    while(!myset.empty())
    {
        ll tmp = myset.top().second;
        //cout << tmp << endl;
        myset.pop();
        if(visit[tmp]) continue;
        visit[tmp] = true;
        for(auto i : adjlis[tmp])
        {
            if(i.risk <= minrisk && dis[i.des] > dis[tmp] + i.w)
            {
                dis[i.des] = dis[tmp] + i.w;
                myset.push({dis[i.des], i.des});
            }
        }
    }
}

void init()
{
    scanf("%lld%lld", &n, &m);
    //cout << n << " " << m << endl;
    for(int i = 0 ; i < 30005 ; i++) adjlis[i].clear();
    for(int i = 0 ; i < m ; i++)
    {
        ll tmp;
        struct QQ tmp1;
        scanf("%lld%lld%lld%lld", &tmp, &tmp1.des, &tmp1.risk, &tmp1.w);
        adjlis[tmp].push_back(tmp1);
    }
}

void sol()
{
    Dijktra_risk();
    minrisk = risk[n - 1];
    if(minrisk == oo)
    {
        printf("-1\n");
        return ;
    }
    printf("%lld ", minrisk);
    Dijktra_path();
    printf("%lld\n", dis[n - 1]);
}

int main()
{
    ll ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();
    }



    return 0;
}

