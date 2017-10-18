#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 5

ll n, p, a, b, c;
ll ch[M][M], ans[M][M];

void init()
{
    ch[0][0] = a;
    ch[0][1] = b;
    ch[0][2] = c;
    ch[1][0] = 1;
    ch[1][1] = 0;
    ch[1][2] = 0;
    ch[2][0] = 0;
    ch[2][1] = 1;
    ch[2][2] = 0;
    memset(ans, 0, sizeof(ans));
    ans[0][0] =ans[1][1] = ans[2][2] = 1;
}

void sol()
{
    ll p3 =  n - 3;
    ll tmp[M][M];
    while(p3 > 0)
    {
        if(p3 & 1)
        {
            memset(tmp, 0, sizeof(tmp));
            for(int i = 0 ; i < 3 ; i++)
                for(int j = 0 ; j < 3 ; j++)
                    for(int k = 0 ; k < 3 ; k++)
                        tmp[i][j] += (ans[i][k] % p) * (ch[k][j] % p) % p;
            for(int i = 0 ; i < 3 ; i++)
                for(int j = 0 ; j < 3 ; j++)
                    ans[i][j] = tmp[i][j];
        }
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                for(int k = 0 ; k < 3 ; k++)
                    tmp[i][j] += (ch[i][k] % p) * (ch[k][j] % p) % p;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                ch[i][j] = tmp[i][j];
        p3 >>= 1;
    }
    cout << (ans[0][0] + ans[0][1] + ans[0][2] ) % p << endl;
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
