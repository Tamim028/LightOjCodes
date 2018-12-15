
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e18

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll arr[100005];
struct info{
    ll prop, sum;
}tree[300005];

void init(ll node, ll b, ll e){
    if(b == e){
        tree[node].sum = arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(ll node, ll b, ll e, ll i, ll j, ll x){
    if(j < b || i > e){
        return;
    }
    if(b >= i && e <= j){
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry){
    if(j < b || i > e){
        return 0;
    }
    if(b >= i && e <= j){
        return tree[node].sum + (carry*(e-b+1));
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);
    return p1+p2;
}

int main()
{

    _FastIO;

    ll tc, tcase = 0, n , c;

    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &n, &c);
        memset(arr, 0, sizeof(arr));
        printf("Case %lld:\n", ++tcase);
        while(c--){
            ll flag, lo, hi, x;
            scanf("%lld", &flag);
            if(flag){
                scanf("%lld %lld", &lo, &hi);
                ll ans =  query(1, 1, n, lo+1, hi+1, 0);
                printf("%lld\n", ans);
            }
            else{
                scanf("%lld %lld %lld", &lo, &hi, &x);
                update(1, 1, n, lo+1, hi+1, x);
            }
        }
        for(ll i = 1; i < 300001; i++){
            tree[i].sum = 0;
            tree[i].prop = 0;
        }
    }

    return 0;
}
