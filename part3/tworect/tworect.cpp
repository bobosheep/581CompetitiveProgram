#include<bits/stdc++.h>
using namespace std;

#define M 505
#define oo 2147483647

int sq[M][M], top[M], down[M];
int l[M], r[M];
int n, ans;

int cal(int tmp[])
{
    int ret(0), maxa(-oo), sum(0);
    for(int i = 0 ; i < n ; i++)
    {
        maxa = max(maxa, tmp[i]);
        sum += tmp[i];
        if(sum < 0)
        {
            sum = 0;
            continue;
        }
        if(ret <= sum)
            ret = sum;
    }
    if(maxa <= 0)
        return maxa;
    else return ret;
}

void init()
{
    ans = -oo;
    for(int i = 0 ; i < M ; i++)
        top[i] = down[i] = l[i] = r[i] = -oo;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d", &sq[i][j]);

}

void sol()
{
    int tmp[M], sum(0);

    for(int i = 0 ; i < n ; i++)
    {
        memset(tmp, 0, sizeof(tmp));
        for(int j = i ; j < n ; j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                tmp[k] += sq[j][k];
            }
            sum = cal(tmp);
            top[i] = max(top[i], sum);
            down[j] = max(down[j], sum);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        memset(tmp, 0, sizeof(tmp));
        for(int j = i ; j < n ; j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                tmp[k] += sq[k][j];
            }
            sum = cal(tmp);
            l[i] = max(l[i], sum);
            r[j] = max(r[j], sum);
        }
    }

    for(int i = 1; i < n ; i++)
    {
        for(int j = i; j < n ; j++)
        {
            ans = max(r[i - 1] + l[j], ans);
            ans = max(down[i - 1] + top[j], ans);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    while (cin >> n && n)
    {
        init();
        sol();
    }

    return 0;
}
