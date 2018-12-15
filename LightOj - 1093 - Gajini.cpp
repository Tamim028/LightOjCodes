#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e9

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int arr[100005];

struct info{
    int val, mx, mn;
}tree[300005];

void init(int node, int b, int e){
    if(b == e){
        //tree[node].val = arr[b];
        tree[node].mx  = arr[b];
        tree[node].mn  = arr[b];
        return;
    }
    int left  = node*2;
    int right = node*2 + 1;
    int mid   = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].mx = max(tree[left].mx, tree[right].mx);
    tree[node].mn = min(tree[left].mn, tree[right].mn);
    return;
}

int query(int node, int b, int e, int i, int j, int ck){
    if(j < b || i > e){
        if(ck){
            return 0;
        }
        else return MAXS;
    }
    if(b >= i && e <= j){
        if(ck){
            return tree[node].mx;
        }
        return tree[node].mn;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j, ck);
    int p2 = query(right, mid+1, e, i, j, ck);
    if(ck){
        return max(p1, p2);
    }
    else return min(p1, p2);
}

int main()
{


    int tc, n, d, tcase = 0;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &d);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        init(1, 1, n);
        int ans = 0;
//        for(int i = 1; i <= 5; i++){
//            cout << tree[i].mx << " " << tree[i].mn << endl;
//        }
        for(int i = 1; i <= n; i++){
            int lo = i;
            int hi = (i+d-1);
            if(lo > n || hi > n){
                break;
            }
            int x = query(1, 1, n, lo, hi, 1);
            int y = query(1, 1, n, lo, hi, 0);
            int z = abs(x-y);
            //cout << "x: " << x << " y: " << y << endl;
            ans = max(ans, z);
        }
        printf("Case %d: %d\n", ++tcase, ans);

    }

    return 0;
}
