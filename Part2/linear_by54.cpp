#include <bits/stdc++.h>

using namespace std;
#define int_m 2147483648
struct line
{
    long long a,b,s,e;
    bool operator <(const line &g)
    {
        if(a==g.a)
        {
            return b>g.b;
        }
        return a<g.a;
    }
};
void clear(stack<line> &f)
{
    stack<line> eap;
    swap(eap,f);
}
int main()
{
    int n,m;
    long long *x;
    line *f;
    stack<line> w;
    while(scanf("%d%d",&n,&m)&&(n))
    {
        f=new line[n];
        x=new long long[m];
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&f[i].a,&f[i].b);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&x[i]);
        }
        sort(f,f+n);
        sort(x,x+m,greater<int>());
        f[0].s=-int_m;
        w.push(f[0]);
        long long last=f[0].a;
        for(int i=1;i<n;i++)
        {
            if(f[i].a==last)
                continue;
            last=f[i].a;
            if(w.size()==1)
            {
                w.top().e=(f[i].b-w.top().b)/(w.top().a-f[i].a);
                f[i].s=w.top().e+1;
                w.push(f[i]);
            }
            else
            {
                long long ns;
                while(1)
                {
                    ns=(w.top().b-f[i].b)/(f[i].a-w.top().a)+1;
                    if(ns<=w.top().s)
                    {
                        w.pop();
                    }
                    else
                        break;
                }
                f[i].s=ns;
                w.top().e=ns-1;
                w.push(f[i]);
            }
        }
        w.top().e=int_m;
        long long ans(0);
        line lst=w.top();
        w.pop();
        for(int i=0;i<m;i++)
        {
            while(!w.empty())
            {
                if(x[i]*lst.a+lst.b<x[i]*w.top().a+w.top().b)
                {
                    lst=w.top();
                    w.pop();
                }
                else
                    break;
            }
            ans+=(lst.a*x[i]+lst.b);
        }
        cout<<ans<<endl;
        delete []f;
        delete []x;
        clear(w);
    }
    return 0;
}
