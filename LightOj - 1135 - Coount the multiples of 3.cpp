#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e18

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct info
{
    int lazy, sum, zer, one, two;
} tree[400005];

void solve(int node, int b, int e)
{
    int n_0 = tree[node].zer;
    int n_1 = tree[node].one;
    int n_2 = tree[node].two;
    if(tree[node].lazy == 1)
    {
        tree[node].two = n_1;
        tree[node].one = n_0;
        tree[node].zer = n_2;
    }
    if(tree[node].lazy == 2)
    {
        tree[node].two = n_0;
        tree[node].one = n_2;
        tree[node].zer = n_1;
    }
}

void init(int node, int b, int e)
{
    tree[node].lazy = 0;
    tree[node].one = 0;
    tree[node].two = 0;
    tree[node].zer = (e-b+1);
    if(b == e)
    {
        tree[node].zer = 1;
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
}

void update(int node, int b, int e, int i, int j)
{
    if(tree[node].lazy)
    {
        solve(node, b, e);
        if(b != e)
        {
            tree[node*2].lazy = (tree[node*2].lazy+tree[node].lazy)%3;
            tree[node*2+1].lazy = (tree[node*2+1].lazy+tree[node].lazy)%3;
        }
        tree[node].lazy = 0;
    }
    if(b > j || e < i)
    {
        return;
    }
    if(b >= i && e <= j)
    {
        tree[node].lazy = (tree[node].lazy+1)%3;
        solve(node, b, e);
        if(b != e)
        {
            tree[node*2].lazy = (tree[node*2].lazy+tree[node].lazy)%3;
            tree[node*2+1].lazy = (tree[node*2+1].lazy+tree[node].lazy)%3;
        }
        tree[node].lazy = 0;
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);

    tree[node].zer = tree[left].zer + tree[right].zer;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
}

int query(int node, int b, int e, int i, int j)
{
    if(tree[node].lazy)
    {
        solve(node, b, e);
        if(b != e)
        {
            tree[node*2].lazy = (tree[node*2].lazy+tree[node].lazy)%3;
            tree[node*2+1].lazy = (tree[node*2+1].lazy+tree[node].lazy)%3;
        }
        tree[node].lazy = 0;
    }
    if(b > j || e < i)
    {
        return 0;
    }
    if(b >= i && e <= j)
    {
        return tree[node].zer;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1+p2;
}

int main()
{

    //_FastIO;

    int tc, tcase = 0, n, q;

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &q);
        init(1, 1, n);
//        for(int i=0; i<=n*4; i++)
//        {
//            printf("tree[%d] = %d\n",i,tree[i].zer);
//        }
        printf("Case %d:\n", ++tcase);
        while(q--)
        {
            int flag, lo, hi;
            scanf("%d %d %d", &flag, &lo, &hi);
            lo++;
            hi++;
            if(flag == 0)
            {
                update(1, 1, n, lo, hi);
            }
            else
            {
                int x = query(1, 1, n, lo, hi);
                printf("%d\n", x);
            }
        }
    }

    return 0;
}
