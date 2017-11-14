#include<bits/stdc++.h>

#define rep(a,b) for(int i=a;i<b;i++)
#define MAX 50005
using namespace std;


int myset[MAX], level[MAX], component[MAX];
int ans, n, edge;

int myfind(int x)
{
    return (myset[x] == x) ? x : myfind(myset[x]);
}

void Union(int x, int y)
{
    x = myfind(x);
    y = myfind(y);
    if(x != y)
    {
        if(level[x] > level[y])
            myset[y] = x, component[x] += component[y];
        else if(level[x] < level[y])
            myset[x] = y, component[y] += component[x];
        else
        {
            myset[y] = x;
            component[x] += component[y];
            level[x]++;
        }
    }
}

void init()
{
    ans = 0;
    cin >> n >> edge;
    rep(0,n)
        myset[i] = i, level[i] = 0;
    rep(0, n)
        scanf("%d", &component[i]);
}

void sol()
{
    int x, y;
    while(edge--)
    {
        scanf("%d%d", &x, &y);
        if(myset[x] == myset[y]) continue;
        Union(x, y);
    }
    rep(0, n)
    {
        ans = max(ans, component[i]);
    }
    cout << ans << endl;
}


int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();
    }


    return 0;
}
