#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> child[1005];//r1~rn
ll value[1005];//r1~rn
ll choose[1005], nchoose[1005];
ll n, ans;

void DP(ll n)
{

    if(child[n].size() == 0)
    {//if it is leaf, return
        choose[n] = value[n];
        nchoose[n] = 0;
        return;
    }
    for(int i = 0 ; i < child[n].size() ; i++)
    {
        DP(child[n][i]);//set all the children's value of choose and value of no-choose
    }

    nchoose[n] = 0;
    choose[n] = value[n];
    for(int i = 0 ; i < child[n].size() ; i++)
    {
        ll chi(child[n][i]);
        choose[n] += nchoose[chi];
        nchoose[n] += max(choose[chi], nchoose[chi]);
    }

}

void init()
{
    ans = 0;
    for(int i = 0 ; i < 1005 ; i++)
        choose[i] = nchoose[i] = value[i] = 0;

    cin >> n >> value[1];
    for(int i = 0 ; i <= n ; i++)
        child[i].clear();

    for(int i = 2 ; i <= n ; i++)
    {
        ll s, r;
        scanf("%lld%lld", &s, &r);
        value[i] = r;
        child[s].push_back(i);
    }

}

void sol()
{
    DP(1);
    ans = max(choose[1], nchoose[1]);
    cout << ans << endl;
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
