#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e18

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int arr[100005], mxx;

int tree[400005];

void init(int node, int b, int e){
    if(b == e){
        tree[node] = b;
        return;
    }
    int Left  = node*2;
    int Right = node*2 + 1;
    int mid = (b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    //tree[node] = min(tree[Left].val, tree[Right].val);
    int mnid;
    int id1 = tree[Left];
    int id2 = tree[Right];
    if(  arr[id1] < arr[id2] ){
        tree[node] = id1;
    }
    else tree[node] = id2;

}

int query(int node, int b, int e, int i, int j){
    if(b > j || e < i){
        return 0;
    }
    if(b >= i && e <= j){
        return tree[node];
    }
    int left  = node*2;
    int right = node*2 + 1;
    int   mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    if( arr[p1] < arr[p2] ){
        return p1;
    }
    else return p2;
}

void solve(int node, int b, int e, int i, int j){
    if(i > j){
        return;
    }
    int x = query(1, b, e, i, j);
    mxx = max(mxx, arr[x]*(j-i+1));
    solve(1, b, e, i, x-1);
    solve(1, b, e, x+1, j);
    return;
}

int main()
{

    //_FastIO;

    int tc, tcase = 0, n;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        init(1, 1, n);
        mxx = 0;
        arr[0] = 1000000000;
        solve(1, 1, n, 1, n);
        printf("Case %d: %d\n", ++tcase, mxx);
    }

    return 0;
}


