#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e18

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll arr[100005];
struct info{
    ll sum, prop;
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
    //tree[node].sum = tree[left].sum + tree[right].sum;
    //tree[node].sum = 0;
    return;
}

void update(ll node, ll b, ll e, ll i, ll j){
    if(j < b || i > e){
        return;
    }
    if(b >= i && e <= j){
        tree[node].prop += 1;
        //cout << "node: " << node << " prop: " << tree[node].prop << endl;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);
}

ll query(ll node, ll b, ll e, ll i, ll carry){
    if(i < b || i > e){
        return 0;
    }
    if(b >= i && e <= i){
        if( (carry+tree[node].prop) & 1){
            return !tree[node].sum;
        }
        return tree[node].sum;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, tree[node].prop + carry);
    ll p2 = query(right, mid+1, e, i, tree[node].prop + carry);
    return p1+p2;
}

int main()
{

   // _FastIO;

    ll tc, tcase = 0, n , c;
    char s[100005];

    scanf("%lld", &tc);
    while(tc--){
        scanf("%s", s);
        ll lenn = strlen(s);
        for(int i = 0; i < lenn; i++){
            arr[i+1] = s[i] - '0';
        }
        init(1, 1, lenn);
//        for(int i = 1; i <= lenn; i++){
//            cout << i << ' ' << arr[i] << endl;
//        }
        scanf("%lld", &c);
        printf("Case %lld:\n", ++tcase);
        while(c--){
            scanf("%s", s);
            ll lo, hi, id;
            if(s[0] == 'I'){
                scanf("%lld %lld", &lo, &hi);
                update(1, 1, lenn, lo, hi);
            }
            else{
                scanf("%lld", &id);
                ll ans = query(1, 1, lenn, id, 0);
                printf("%lld\n", ans);
            }
        }
        for(int i = 1; i < 300001; i++){
            tree[i].sum = 0;
            tree[i].prop = 0;
        }
    }


    return 0;
}
