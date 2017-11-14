#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define P 1000000007

ll num, ans;
priority_queue<ll, vector<ll> , less<ll> > big;
priority_queue<ll, vector<ll> , greater<ll> > small;

void sol()
{
    ll bs = big.size();
    ll ss = small.size();
    ll median;
    //cout << bs << endl;
    //if(bs > 0) printf("Big queue is %lld\n", big.top());
    //if(ss > 0) printf("Small queue is %lld\n", small.top());
    if(bs == 0)
    {
         big.push(num);
         bs++;
    }

    else if(num > big.top())
    {
        small.push(num);
        //cout << "!" << small.top() << endl;
        ss++;
    }
    else
    {
        big.push(num);
        //cout << "!" << big.top() << endl;
        bs++;
    }
    //cout << bs << " " << ss << endl;
    if(bs == ss)
    {
        median = (big.top() + small.top()) / 2;
    }
    else if(bs > ss)
    {
        while(bs - ss >= 2)
        {
            ll tmp = big.top();
            small.push(tmp);
            ss++;
            big.pop();
            bs--;

        }
        if((bs + ss) % 2 )  median = big.top();
        else
            median = (big.top() + small.top()) / 2;
        //cout << "here is " << median << endl;
    }
    else
    {
        while(ss - bs >= 2)
        {
            ll tmp = small.top();
            big.push(tmp);
            bs++;
            small.pop();
            ss--;

        }
        if((bs + ss) % 2 )  median = small.top();
        else
            median = (big.top() + small.top()) / 2;
    }
    //cout << median << endl;
    ans = (ans + median) % P;
}

int main()
{
    ans = 0;
    //freopen("in.txt", "r", stdin);
    while(cin >> num)
    {
        //cout << "Num is " << num << ":\n";
        sol();
    }
    cout << ans ;

    return 0;
}
