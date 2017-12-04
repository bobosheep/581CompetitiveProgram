#include<bits/stdc++.h>
using namespace std;

multiset<int> pokemon;

int main()
{
    int n;
    while(cin >> n && n)
    {
        int l , r;
        pokemon.clear();
        for(int i = 0 ; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            multiset<int>::iterator it;
            //it = pokemon.find(l);
            //cout << "~~~" << l << " " << r << endl;
            pokemon.insert(l);
            it = pokemon.upper_bound(r);
            if(it != pokemon.end())
            {
                //cout << *it << endl;
                pokemon.erase(it);
            }
        }

        cout << pokemon.size() << endl;
    }

    return 0;
}
