#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;

vector<ll> ans;
ll nnum;

void init()
{
    ans.clear();
    for(int i = 0 ; i < nnum ; i++)
    {
        ll tmp;
        scanf("%lld", &tmp);
        auto it = lower_bound(ans.begin(), ans.end(), tmp);
        if(it == ans.end()) ans.push_back(tmp);
        else *it = tmp;
    }
    cout << ans.size() << endl;
}

int main()
{
    ll ncase;
    cin >> ncase;
    while(ncase--)
    {
        cin >> nnum;
        init();
    }


    return 0;
}
