#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> iip;
typedef vector<iip > iipv;
#define rep(a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define MAX_R 10005

const int INF(2147483647);

int npoint, nedge;
int longdis[MAX_R], dist[MAX_R];
iipv adjlist[MAX_R];
iip nextpoint;
priority_queue<iip, iipv, greater<iip> > myset;

void Dijktra()
{
    rep(0, npoint)
    {
        dist[i] = INF;
        longdis[i] = 0;
    }
    dist[0] = 0;
    myset.push(mp(0, 0));
    while(!myset.empty())
    {
        nextpoint = myset.top();
        myset.pop();
        for(auto i : adjlist[nextpoint.second])
        {
            if(dist[i.first] > nextpoint.first + i.second )
            {
                dist[i.first] = nextpoint.first + i.second;
                myset.push({dist[i.first], i.first});
                longdis[i.first] = longdis[nextpoint.second] + 1;
            }
        }
    }
    /*rep(0, npoint)
        cout << dist[i] << " ";
    cout << endl;*/
}

int main()
{
    int ans(0);
    cin >> npoint >> nedge;
    rep(0, nedge)
    {
        int u, v, cost;
        scanf("%d%d%d", &u, &v, &cost);
        adjlist[u].pb(mp(v, cost));
        adjlist[v].pb(mp(u, cost));
    }
    Dijktra();
    rep(0, npoint)
    {
        if(dist[i] > dist[ans])
            ans = i;
    }
    cout << dist[ans] << endl;

    return 0;
}
