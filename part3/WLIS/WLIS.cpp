#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;

typedef map<ll, ll> mpll;
#define mplli mpll::iterator

mpll wlis;
ll nnum, num[150005];
ll ans;

void init()
{
    ans = 0;
    wlis.clear();
    for(int i = 0 ; i < nnum ; i++)
    {
        scanf("%lld", &num[i]);
    }
    wlis.insert({-1, 0});
    for(int i = 0 ; i < nnum ; i++)
    {
        ll tmp, now_weight;
        mplli it;
        scanf("%lld", &tmp);
        it = wlis.lower_bound(num[i]);
        it--;

        now_weight = it->second + tmp;
        ans = max(now_weight, ans);

        it = wlis.insert(it, make_pair(num[i], now_weight));

        if(it->second < now_weight)
            it->second = now_weight;
        it++;
        while(it != wlis.end() && it->second <= now_weight)
            it = wlis.erase(it);
    }

    cout << ans << endl;
}

int main()
{
    ll ncase;
    //freopen("td.txt", "r", stdin);
    cin >> ncase;
    while(ncase--)
    {
        cin >> nnum;
        init();
    }


    return 0;
}

