#include<bits/stdc++.h>
using namespace std;

#define _MAX 1000007
#define MAX 505
#define rep(a,b) for(int i = a ; i < b ; i++)
#define pb push_back

int risk[MAX][MAX];
int npoint, npath;
int dp[MAX] , ans;
bool go[MAX];

/*void dfs(int x)
{
    if(!go[x] || x == npoint - 1) return ;
    go[x] = false;
    //cout << x << " " << dp[x] << endl;
    rep(0, npoint)
    {
        if(risk[x][i] > 0 && go[i])
        {
            if(dp[i] == _MAX)
                dp[i] = max(dp[x], risk[x][i]);
            else dp[i] = min(dp[i], max(risk[x][i], dp[x]));
            dfs(i);
        }
    }
    go[x] = true;
}*/

void init()
{
    cin >> npoint >> npath;
    memset(go, 1, sizeof(go));
    rep(0, npoint)
        for(int j = 0 ; j < npoint ; j++)
            risk[i][j]=_MAX;
    rep(0, npath)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        risk[x][y] = r;
    }

}

void sol()
{
    //dp[0] = 0;
    //dfs(0);
    for(int k = 1 ; k < npoint ; k++)
        for(int i = 0 ; i < npoint ; i++)
            for(int j = 0 ; j < npoint ; j++)
                if(i != j && j != k)
                    risk[i][j] = min(risk[i][j], max(risk[i][k], risk[k][j]));
    ans = (risk[0][npoint - 1] == _MAX ? -1 : risk[0][npoint - 1]);
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
