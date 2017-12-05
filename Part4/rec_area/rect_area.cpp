#include<bits/stdc++.h>
using namespace std;

#define EDGE  120000

struct SEG
{
    int l, r;
    int cover;
    int len;
}seg[1000005];

void build(int l, int r, int index);
void range_update(int l, int r, int index, int value);
void range_query(int l, int r, int index);

struct line
{
    int x, y1, y2;
    int value;
    bool operator < (line a) const
    {
        return x < a.x;
    }
};


int n, query;
vector<line> l;
clock_t t1, t2;

void init()
{

    cin >> n;
    //cout << "!";
    build(0, EDGE + 1, 1);

    //cout << ((long double)(t2 - t1)) / CLOCKS_PER_SEC << endl;
    l.clear();
    query = 0;
    for(int i = 0 ; i < n ; i++)
    {
        line tmp, tmp1;
        int x1, x2;
        scanf("%d%d%d%d", &x1, &tmp.y1, &x2, &tmp.y2);
        //cout << i << endl;
        if(x1 > x2)
        {
            tmp.x = x2;
            tmp.value = 1;
            tmp1.x = x1;
            tmp1.value = -1;
        }
        else
        {
            tmp.x = x1;
            tmp.value = 1;
            tmp1.x = x2;
            tmp1.value = -1;
        }
        if(tmp.y1 > tmp.y2)
            tmp.y1 ^= tmp.y2 ^= tmp.y1 ^= tmp.y2;

        tmp1.y1 = tmp.y1;
        tmp1.y2 = tmp.y2;

        l.push_back(tmp);
        l.push_back(tmp1);
    }
    sort(l.begin(), l.end());

}

void sol()
{
    long long ans(0);
    t1 = clock();
    for(int i = 0 ; i < l.size()-1 ; i++)
    {
        range_update(l[i].y1, l[i].y2 , 1, l[i].value);

        ans += (l[i + 1].x - l[i].x) * seg[1].len;
        //cout << ans << endl;
    }
    t2 = clock();
    //cout << ((long double)(t2 - t1)) / ((long double)CLOCKS_PER_SEC) << endl;
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int ncase;

    cin >> ncase;
    while(ncase--)
    {
        init();
        sol();

    }

    return 0;
}


///for segment tree
void build(int l, int r, int index)     //n should plus 1
{
    if(l >= r || l > EDGE + 1)
        return;
    int mid = (l + r) / 2;
    seg[index].l = l;
    seg[index].r = r;
    seg[index].cover = 0;
    seg[index].len = 0;
    if(r - l == 1)
        return ;
    build(l, mid, index << 1);
    build(mid, r, (index << 1) | 1);

}

void pushup(int index)
{
    if(seg[index].cover)
        seg[index].len = seg[index].r - seg[index].l;
    else if(seg[index].r - 1 == seg[index].l)
        seg[index].len = 0;
    else
        seg[index].len = seg[index << 1].len + seg[index << 1 | 1].len;
}

void range_update(int l, int r, int index, int value)   //r don't plus one
{
    if(r < seg[index].l || l >= seg[index].r)
        return;

    int mid = (seg[index].l + seg[index].r) / 2;
    if(seg[index].r == r && seg[index].l == l)
    {
        seg[index].cover += value;
        pushup(index);
        return;
    }
    if(r < mid)
        range_update(l, r, index << 1, value);
    else if(l >= mid)
        range_update(l, r, (index << 1) | 1, value);
    else
    {
        range_update(l, mid, index << 1, value);
        range_update(mid, r, (index << 1) | 1, value);
    }

    pushup(index);
}


