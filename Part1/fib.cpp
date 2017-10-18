#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, c;
ll n, p, ans;
ll base[5][5], res[5][5];

void init()
{
    base[0][0] = a;
    base[0][1] = b;
    base[0][2] = c;
    base[1][0] = 1;
    base[1][1] = 0;
    base[1][2] = 0;
    base[2][0] = 0;
    base[2][1] = 1;
    base[2][2] = 0;
    memset(res, 0, sizeof(res));
    res[0][0] = res[1][1] = res[2][2] = 1;
}

void sol()
{
    ll tmp[5][5];
    int n3 = n - 3;
    while(n3 > 0)
    {
        if(n3 & 1)
        {
            //res = res * base % p;

            memset(tmp, 0, sizeof(tmp));
            for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3 ; j++)
                {
                    for(int k = 0 ; k < 3 ; k++)
                    {
                        tmp[i][j] += ((res[i][k] % p) * (base[k][j] % p)) % p;
                    }
                }
            }
            for(int i = 0 ; i < 3 ; i++)
                for(int j = 0 ; j < 3 ; j++)
                    res[i][j] = tmp[i][j] % p;
            /*for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3 ; j++)
                    cout << res[i][j] << " ";
                cout << endl;
            }*/

        }

        memset(tmp, 0, sizeof(tmp));
        //base = base * base;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                for(int k = 0 ; k < 3 ; k++)
                {
                    tmp[i][j] += ((base[i][k] % p) *(base[k][j] % p)) % p;
                }
            }
        }
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                base[i][j] = tmp[i][j] % p;

        n3 >>= 1;
    }

    ans = (res[0][0] + res[0][1] + res[0][2]) % p;
    cout << ans << endl;

}

int main()
{
    while(cin >> n >> p >> a >> b >> c)
    {
        init();
        sol();
    }

    return 0;
}
