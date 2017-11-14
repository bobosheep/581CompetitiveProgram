#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define oo 2147483647

priority_queue<pair<ll, ll > , vector<pair<ll, ll> > > small;
priority_queue<pair<ll, ll > , vector<pair<ll, ll> > , greater<pair<ll, ll > > > big;
ll nnum, range, num[500005];
ll ans;

ll ab(ll a, ll b)
{
    return (a - b) > 0 ? (a - b) : (b - a);
}

void init()
{
    while(!small.empty()) small.pop();
    while(!big.empty()) big.pop();
    ans = -oo;
    scanf("%lld", &num[0]);
    small.push({num[0], 0});
    big.push({num[0], 0});
}

void sol()
{
    for(int i = 1 ; i < nnum ; i++)
    {
        scanf("%lld", &num[i]);
        pair<ll, ll> tmp1, tmp2;
        tmp1 = small.top();
        tmp2 = big.top();
        while(!small.empty() && i - tmp1.second > range) {small.pop(); tmp1 = small.top();}
        while(!big.empty() && i - tmp2.second > range) {big.pop(); tmp2 = big.top();}
        ans = max(ans, ab(tmp1.first, num[i]));
        ans = max(ans, ab(tmp2.first, num[i]));
        small.push({num[i], i});
        big.push({num[i], i});
    }
    cout << ans << endl;
}

int main()
{

    while(scanf("%lld %lld", &nnum, &range) == 2  && nnum)
    {
        init();
        sol();
    }

    return 0;
}
