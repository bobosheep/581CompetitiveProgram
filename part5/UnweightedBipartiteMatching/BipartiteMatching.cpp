#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 505

ll n, m, t, ans;
bool match[M][M];
ll mx[M], my[M];
bool visit[M];

bool DFS(int x)
{
    for(int i = 0 ; i < m ; i++)
        if(match[x][i] && !visit[i])
        {
            visit[i] = true;
            if(my[i] == -1 || DFS(my[i]))
            {
                //§ä¨ìÂX¥R¸ô®|
                mx[x] = i;
                my[i] = x;
                return true;
            }

        }
    return false;
}

void init()
{
    memset(match, 0, sizeof(match));
    ans = 0;
    cin >> n >>m >> t;


    for(int i = 0 ; i < t ; i++)
    {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        match[xx][yy] = true;
    }
}

void bipartite()
{
    for(int i = 0 ; i < M ; i++)
        mx[i] = my[i] = -1;

    for(int i = 0 ; i < n ; i++)
        if(mx[i] == -1)
        {
            memset(visit, 0, sizeof(visit));
            if(DFS(i)) ans++;
        }
}

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        bipartite();
        cout << ans << endl;
    }

    return 0;
}
