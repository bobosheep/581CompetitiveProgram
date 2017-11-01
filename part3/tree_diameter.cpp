#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll parent[100005], longest[100005], nnum;
bool visit[100005];
ll child[100005];
ll ans, __max;
queue<ll> que;


void init()
{
    ans = 0;
    __max = 0;
    while(!que.empty()) que.pop();
    for(int i = 0 ; i < nnum ; i++)
    {
        visit[i] = false;
        parent[i] = i;
        child[i] = 0;
        longest[i] = 0;
    }
    for(int i = 0 ; i < nnum - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        parent[b] = a;
        child[a]++;
    }
    for(int i = 0 ; i < nnum ; i++)
    {
        if(parent[i] != i && child[i] == 0)
        {
            que.push(i);
        }
    }
}

void sol()
{
    while(!que.empty())
    {
        ll now_p, now = que.front();
        que.pop();
        now_p = parent[now];
        if(now_p == now) break;
        __max = longest[now] + 1 + longest[now_p];
        ans = max(__max, ans);
        if(longest[now] + 1 > longest[now_p]) longest[now_p] = longest[now] + 1;
        child[now_p]--;
        if(child[now_p] == 0) que.push(now_p);
    }
}

int main()
{
    ll ncase, findx;
    cin >> ncase;
    while(ncase--)
    {
        cin >> nnum;
        init();
        sol();
        cout << ans << endl;
    }


    return 0;
}
