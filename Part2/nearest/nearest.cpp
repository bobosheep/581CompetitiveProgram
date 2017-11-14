#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

stack<ll> lis;
ll n, ans;
ll num[200005];

void init()
{
    for(int i = 0 ; i < n ; i++)
        scanf("%lld", &num[i]);
    lis.push(num[0]);
    ans = 0;
}

void sol()
{
    for(int i = 1 ; i < n ; i++)
    {
        while(!lis.empty() && num[i] <= lis.top())
            lis.pop();
        if(lis.empty())
            lis.push(num[i]);
        else
        {
            //cout << i << endl;
            ans += num[i] - lis.top();
            lis.push(num[i]);
        }
    }
    while(!lis.empty()) lis.pop();
    cout << ans << endl;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0) break;
        init();
        sol();
    }

    return 0;
}
