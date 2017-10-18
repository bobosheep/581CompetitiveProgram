#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define xx first
#define yy second
#define pb push_back
#define mk make_pair
#define rep(a,b) for(int i=a; i<b ; i++)
#define oo 2147483647

struct XD
{
    ll left, a, b;
};

ll n, m, ans;
vpll line;
vector<ll> c;
stack<struct XD> bstline;


inline ll xfind(pll a, pll b)
{
    return (b.yy - a.yy) / (a.xx - b.xx);
}

void init()
{
    struct XD tmp;
    ans = 0;
    c.clear();
    line.clear();
    while(!bstline.empty()) bstline.pop();
    rep(0, n)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        line.pb(mk(a, b));
    }
    rep(0, m)
    {
        ll x;
        scanf("%lld", &x);
        c.pb(x);
    }
    sort(line.begin(), line.end());
    sort(c.begin(), c.end(), greater<ll>());
    tmp = {-oo, line[0].xx, line[0].yy};
    bstline.push(tmp);
}

void sol()
{
    struct XD tmp, tmp1;
    rep(1, n)
    {
        tmp = bstline.top();
        if(tmp.a == line[i].xx)
        {
            if(bstline.size() == 1 && line[i].yy > tmp.b)
            {
                bstline.pop();
                tmp1 = {-oo, line[i].xx, line[i].yy};
                bstline.push(tmp1);
            }
            else if(line[i].yy > tmp.b)
            {
                bstline.pop();
                tmp = bstline.top();
                ll nowleft = xfind(line[i], mk(tmp.a, tmp.b));
                while(nowleft <= tmp.left)
                {
                    bstline.pop();
                    tmp = bstline.top();
                    nowleft = xfind(line[i], mk(tmp.a, tmp.b));
                }
                tmp1 = {nowleft, line[i].xx, line[i].yy};
                bstline.push(tmp1);
            }
        }
        else
        {
            ll nowleft = xfind(line[i], mk(tmp.a, tmp.b));
            while(nowleft <= tmp.left)
            {
                bstline.pop();
                tmp = bstline.top();
                nowleft = xfind(line[i], mk(tmp.a, tmp.b));
            }
            tmp1 = {nowleft, line[i].xx, line[i].yy};
            bstline.push(tmp1);
        }
    }
    tmp = bstline.top();
    bstline.pop();
    rep(0, m)
    {
        while(!bstline.empty())
        {
            if(tmp.a * c[i] + tmp.b < bstline.top().a * c[i] + bstline.top().b)
            {
                tmp = bstline.top();
                bstline.pop();
            }
            else break;
        }
        ans += tmp.a * c[i] + tmp.b;
    }
    cout << ans << endl;

}

int main()
{
    while(cin >> n >> m  && n)
    {
        init();
        sol();
    }

    return 0;
}

