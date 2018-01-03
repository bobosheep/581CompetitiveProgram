#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 10005
#define oo 1000000007

int n, m;
ll flow[M][M], ori[M][M];
ll ans;
int parent[M];
bool visit[M];
queue<int> q;

int BFS(int s, int t)
{
    ll neck = oo;
    while(!q.empty()) q.pop();
    q.push(s);

    memset(visit, 0, sizeof(visit));
    for(int i = 0 ; i < n ; i++)  parent[i] = i;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(visit[now]) continue;
        visit[now] = true;
        if(now == t) break;
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
    return visit[t] ? neck : 0;
}

void init()
{

    ans = 0;
    memset(visit, 0, sizeof(visit));
    memset(flow, 0 , sizeof(flow));
    memset(ori, 0, sizeof(ori));
    for(int i = 0 ; i < n ; i++)  parent[i] = i;


    scanf("%d%d", &n, &m);

    for(int i = 0 ; i < m ; i++)
    {
        ll x, y, w;
        scanf("%lld%lld%lld", &x, &y, &w);
        ori[x][y] = flow[x][y] = w;
        ori[y][x] = flow[y][x] = w;
    }
}

void maxflow()
{
    ll neck;
    ll s, t;
    s = 0;
    t = n - 1;
    while(neck = BFS(s, t))
    {
        //printf("%lld\n", neck);
        for(int i = t ; i != s ; i = parent[i])
        {
            //printf("%d ", i);
            flow[parent[i]][i] -= neck;
            flow[i][parent[i]] += neck;
        }
        //printf("\n");

    }
}

void DFS(int s)
{
    visit[s] = true;
    for(int i = 0 ; i < n ; i++)
        if(!visit[i] && flow[s][i] < ori[s][i])
            DFS(i);
}

void sol()
{
    maxflow();

    memset(visit, 0, sizeof(visit));

    ll s = 0;
    DFS(s);

    for(int i = 0 ; i < n ; i++)
        if(visit[i])
            for(int j = 0 ; j < n ; j++)
                if(!visit[j] && ori[i][j])
                    ans += ori[i][j];
    cout << ans << endl;
}

int main()
{
    freopen("min_cut.in", "r", stdin);
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();

    }

    return 0;
}

