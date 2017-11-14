#include<bits/stdc++.h>
using namespace std;


int main()
{
    string num;
    long long p, p2;
    long long sum, base, ans;

    while(cin >> num >> p)
    {
        sum = 0;   //a
        for(auto i : num)
        {
            sum = (sum * 10 + i - '0') % p;
            //cout << sum << endl;
        }
        base = sum;
        ans = 1;
        p2 = p - 2;
        while(p2 > 0)
        {
            if(p2 & 1)
            {
                ans = ((ans % p) * (base % p)) % p;
            }
            base = ((base % p) * (base % p)) % p;
            p2 >>= 1;
        }
        cout << ans  << endl;
    }

    return 0;
}
