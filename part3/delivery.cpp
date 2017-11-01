#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nnum, ans;
vector<ll> wtime;

int main()
{
    ll ncase, nowtime;
    cin >> ncase;
    while(ncase--)
    {
        wtime.clear();
        ans = 0;
        cin >> nnum;
        for(int i = 0 ; i < nnum ; i++)
        {
            ll tmp;
            scanf("%lld", &tmp);
            wtime.push_back(tmp);
        }
        sort(wtime.begin(), wtime.end());
        ans += wtime[0];
        nowtime = ans;
        for(int i = 1 ; i < wtime.size() ; i++)
        {
            nowtime += wtime[i - 1] + wtime[i];
            ans += nowtime;
        }
        cout << ans << endl;
    }

    return 0;
}
