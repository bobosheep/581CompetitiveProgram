#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> base;
ll ans, N, K;

void bi(ll l, ll r)
{
    ll mid = (l + r) / 2;
    ll tmp = K, tmp_base;
    bool can(1);
    //cout << l << " " << r << " " << mid << endl;
    if(l >= r )
    {
        ans = mid;
        return ;
    }
    tmp_base = base[0];
    tmp--;
    for(int i = 1 ; i < base.size() ; i++)
    {
        if(tmp < 0)
        {
            can = false;
            break;
        }
        if(base[i] - tmp_base > mid)
        {
            tmp_base = base[i];
            tmp--;
        }
    }
    if(tmp < 0) can = false;
    if(can) bi(l, mid);
    else bi(mid + 1, r);
}

void init()
{
    cin >> N >> K;
    ans = 0;
    base.clear();
    for(int i = 0 ; i < N ; i++)
    {
        ll tmp;
        scanf("%lld", &tmp);
        base.push_back(tmp);
    }
    sort(base.begin(), base.end());
}

void sol()
{
    if(K == 1)
    {
        cout << base.back() - base.front() << endl;
        return ;
    }
    bi(base.front(), base.back());
    cout << ans << endl;
}

int main()
{
    int ncase;
    cin >> ncase ;
    while(ncase--)
    {
        init();
        sol();
    }

    return 0;
}

