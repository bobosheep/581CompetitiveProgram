#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll > pll;
typedef vector<pll > vpll;
#define rep(a, b) for(int i = a ; i < b ; i++)
#define mk make_pair
#define pb push_back
#define ppb pop_back
#define xx first
#define yy second
#define oo 2147483647

ll n, m, ans;
vpll line;
struct XD
{
    ll left, a, b;
};
stack<struct XD > bstline;
vector<ll> c;

void init()
{
    struct XD tmp;
    line.clear();
    c.clear();
    while(!bstline.empty()) bstline.pop();
    ans = 0;
    rep(0, n)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        line.pb(mk(a, b));
    }
    rep(0, m)
    {
        ll tmp;
        scanf("%lld", &tmp);
        c.pb(tmp);
    }
    sort(line.begin(), line.end());
    sort(c.begin(), c.end(), greater<ll>());
    tmp.left = -oo;
    tmp.a = line[0].xx;
    tmp.b = line[0].yy;
    bstline.push(tmp);
}

void sol()
{
    rep(1, n)
    {
        struct XD tmp, tmp1;
        tmp = bstline.top();
        //printf("size is %d ~%lld %lld %lld\n", bstline.size(), tmp.left, tmp.a, tmp.b);

        if(line[i].xx == tmp.a)
        {
            if(line[i].yy > tmp.b)
            {
                if(bstline.size() == 1)
                {
                    bstline.pop();
                    tmp1 = {-oo, line[i].xx, line[i].yy};
                    bstline.push(tmp1);
                }
                else
                {
                    bstline.pop();
                    tmp = bstline.top();
                    ll nowleft = (-line[i].yy + tmp.b) / (line[i].xx - tmp.a);
                    while(nowleft <= tmp.left && !bstline.empty())
                    {
                        bstline.pop();
                        tmp = bstline.top();
                        nowleft = (-line[i].yy + tmp.b) / (line[i].xx - tmp.a);
                    }
                    if(bstline.empty()) nowleft = -oo;
                    tmp1 = {nowleft, line[i].xx, line[i].yy};
                    bstline.push(tmp1);
                }
            }
            continue;
        }
        else
        {
            //cout << tmp.left;
            ll nowleft = (-line[i].yy + tmp.b) / (line[i].xx - tmp.a);
            while(nowleft <= tmp.left)
            {
                bstline.pop();
                tmp = bstline.top();
                nowleft = (-line[i].yy + tmp.b) / (line[i].xx - tmp.a);
                //cout << "??";
            }
            tmp1 = {nowleft, line[i].xx, line[i].yy};
            bstline.push(tmp1);
        }
    }
    /*for(auto i : bstline)
    {
        printf("%lld %lld %lld\n", i.left, i.a, i.b);
    }
    */
    struct XD chs;
    chs = bstline.top();
    bstline.pop();
    rep(0, m)
    {
        while(!bstline.empty())
        {
            struct XD tmp = bstline.top();
            if(chs.a * c[i] + chs.b < tmp.a * c[i] + tmp.b)
            {
                chs = tmp;
                bstline.pop();
            }
            else break;
        }
        ans += chs.a * c[i] + chs.b;
    }
    cout << ans << endl;
}

int main()
{
    while(cin >> n >> m && n)
    {
        init();
        sol();
    }

    return 0 ;
}
