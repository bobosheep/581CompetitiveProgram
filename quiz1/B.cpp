#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, p;
string xx, n;

void sol()
{
    ll ans = 1, tmp = x;
    for(int k = n.size() - 1 ; k >= 0;)
    {
        //printf("n[%d] is %c\n", k, n[k]);
        for(int i = 0 ; i < (n[k] - '0') ; i++)
            ans = (ans % p) * (x % p) % p;

        tmp = x;
        for(int i = 0 ; i < 9 ; i++)
            x = (tmp % p) * (x %p) % p;
        k--;
    }
    cout << ans % p << endl;
}

int main()
{
    while(cin >> xx >> n >> p )
    {
        x = 0;
        for(int i = 0 ; i < xx.size() ; i++)
            x = (x * 10 + xx[i] - '0') % p;
        //cout << x << endl;
        sol();
    }

    return 0;
}
