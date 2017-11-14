#include<bits/stdc++.h>
using namespace std;

#define rep(a,b) for(int i=a;i<=b;i++)
#define rrep(a,b) for(int i=a;i>b;i--)

long long n, k, p;
long long base, ans;

long long inverse(int num)
{
    long long a, b, c;
    c = p - 2;
    a = 1;
    b = num;
    while(c > 0)
    {
        if(c & 1)
        {
            a = ((a % p) * (b % p)) % p;
            //cout << a << endl;
        }
        b = ((b % p) * (b % p)) % p;
        c >>= 1;
    }
    //cout << a << endl;
    return a;
}

void init()
{
    base = 1;
    ans = 1;
    if(k < n / 2)
    {
        rrep(n, n-k)
        {
            ans = ((ans % p) * (i % p)) % p;
            //cout << i;
        }
    }
    else
    {
        rrep(n, k)
        {
            ans = ((ans % p) * (i % p)) % p;
        }
    }
    //cout << ans << endl;
}

void sol()
{
    if(k < n / 2)
    {
        rep(2, k)
        {
            ans = ((ans % p) * inverse(i)) % p;
            //cout << inverse(i) ;
        }
    }
    else
    {
        rep(2, n - k)
        {
            ans = ((ans % p) * inverse(i)) % p;
        }
    }
    cout << ans % p << endl;
}



int main()
{
    while(cin >> n >> k >> p)
    {
        init();
        sol();
    }

    return 0;
}
