#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1002
#define oo 10000007

int floyd[M][M];

void sol()
{
    int n, m;

    int minsum, minidx;

    scanf("%d%d", &n, &m);


    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < n ; j++)
            floyd[i][j] = i == j ? 0 : oo;

    minsum = oo;

    for(int i = 0 ; i < m ; i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        floyd[x][y] = v;
    }

    for(int k = 0 ; k < n ; k++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            ll tmp(0);
            for(int j = 0 ; j < n ; j++)
            {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                tmp += floyd[i][j];
            }
            if(tmp < minsum)
            {
                minsum = tmp;
                minidx = i;
            }
        }
    }

    printf("%d\n", minidx);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {
        sol();
    }


    return 0;
}
