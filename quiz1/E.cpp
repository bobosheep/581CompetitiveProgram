#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> x;

int main()
{
    ll num;
    while(cin >> num)
    {
        x.push_back(num);
        sort(x.begin(), x.end());
        if(x.size() & 1)
        {
            cout << x[x.size() / 2] << endl;
        }
        else
        {
            cout << (x[x.size() / 2] + x[x.size() / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}

