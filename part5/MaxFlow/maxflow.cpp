/*************

while(BFS)
    path
    r[u][v] -= flow
    r[v][u] += flow
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 505
#define oo 1000000007

int n, m;
ll flow[M][M];
ll ans;
int parent[M];
bool visit[M];
queue<int> q;

int BFS()
{
    ll neck = oo;
    while(!q.empty()) q.pop();
    q.push(0);

    memset(visit, 0, sizeof(visit));
    for(int i = 0 ; i < n ; i++)  parent[i] = i;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(visit[now]) continue;
        visit[now] = true;
        for(int i = 0 ; i < n ; i++)
        {
            if(flow[now][i] > 0 && !visit[i])
            {
                q.push(i);
                parent[i] = now;
                neck = min(neck, flow[now][i]);
            }
        }
    }
    return visit[n - 1] ? neck : 0;
}

void init()
{

    ans = 0;
    memset(visit, 0, sizeof(visit));
    memset(flow, 0 , sizeof(flow));
    for(int i = 0 ; i < n ; i++)  parent[i] = i;


    scanf("%d%d", &n, &m);

    for(int i = 0 ; i < m ; i++)
    {
        ll x, y, w;
        scanf("%lld%lld%lld", &x, &y, &w);
        flow[x][y] = w;
    }
}

void sol()
{
    ll neck;

    while(neck = BFS())
    {
        //printf("%lld\n", neck);
        for(int i = n - 1 ; i != 0 ; i = parent[i])
        {
            //printf("%d ", i);
            flow[parent[i]][i] -= neck;
            flow[i][parent[i]] += neck;
        }
        //printf("\n");
        ans += neck;
    }
    printf("%lld\n", ans);
}

int main()
{
    //freopen("Max_Flow.in", "r", stdin);
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();

    }

    return 0;
}
