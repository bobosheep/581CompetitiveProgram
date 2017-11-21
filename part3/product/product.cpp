#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[50], prime, invertnum[50];
ll ans, nnum, half_index, product, find1;
vector<ll> half1, half2;

ll invert(ll n)
{
    ll tmp(n), ret(1), p(prime - 2);
    while(p > 0)
    {
        if(p & 1)
        {
            ret = ( (ret % prime) * (tmp % prime) )% prime;
        }
        tmp = ((tmp % prime) * (tmp % prime)) % prime;
        p >>= 1;
    }
    return ret;
}

void DP(int n)
{
    if(n >= half_index)
    {
        half1.push_back(product);
        return;
    }
    product = ((product % prime )* (num[n] % prime)) % prime;       //choose
    DP(n + 1);
    product =((product % prime) * (invertnum[n] % prime)) % prime;  //not choose
    DP(n + 1);
}

void DP2(int n)
{
    if(n >= nnum)
    {
        half2.push_back(product);
        return;
    }
    product = ((product % prime )* (invertnum[n] % prime)) % prime;       //choose
    DP2(n + 1);
    product =((product % prime) * (num[n] % prime)) % prime;  //not choose
    DP2(n + 1);
}

void init()
{
    cin >> nnum >> prime;
    half_index = nnum / 2;
    find1 = ans = 0;
    half1.clear();
    half2.clear();
    for(int i = 0 ; i < nnum ; i++)
        scanf("%lld", &num[i]);

    sort(num, num + nnum);
    for(int i = 0 ; i < nnum ; i++)
        invertnum[i] = invert(num[i]) % prime;
}

void sol()
{
    ll tmp1, tmp2;
    product = 1;
    DP(0);
    product = 1;
    DP2(half_index);


    sort(half1.begin(), half1.end());
    sort(half2.begin(), half2.end());
    tmp1 = tmp2 = 0;

    for(int i = 0 , j = 0 ; i < half1.size() && j < half2.size() ;)
    {
        if(half1[i] > half2[j])
        {   j++;    continue;   }

        else if(half1[i] < half2[j])
        {   i++;    continue;   }

        while(half1[i] == half2[j])
            tmp1++, i++;

        while(i && half1[i - 1] == half2[j])
            tmp2++, j++;


        ans += tmp1 * tmp2;
        tmp1 = tmp2 = 0;
    }

    if(ans == 0) printf("0\n");
    else printf("%lld\n", ans - 1);
}

int main()
{

    ll ncase;
    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();
    }

    return 0;
}
