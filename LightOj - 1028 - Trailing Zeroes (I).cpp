#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS 1000005

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

ll prime[MAXS+5], pn;
bool mark[MAXS+5];

void sieve(){
    //memset(div, 0, sizeof(div));
    memset(mark, 0, sizeof(mark));
    for(ll i = 4; i <= MAXS; i+=2){
        mark[i] = 1;
        //div[i]++;
    }
    mark[0] = 1;
    mark[1] = 1;
    prime[1] = 2;
    pn = 1;
    for(ll i = 3; i <= MAXS; i+=2){
        if(mark[i] == 0){
            prime[++pn] = i;
            for(ll j = i*i; j <= MAXS; j += 2*i){
                mark[j] = 1;
            }
        }
    }
}

ll fun(ll n){
    ll ans = 1;
    //ll sro = sqrt(n);
    for(ll i = 1; i <= pn && prime[i] <= sqrt(n); i++){
        if(n%prime[i] == 0){
            ll cnt = 0;
            while(n%prime[i] == 0){
                n /= prime[i];
                cnt++;
            }
            ans *= (cnt+1);
        }
        //sro = sqrt(n);
    }
    if(n!=1){
        ans *= 2;
    }
    return ans;
}

int main()
{
    //_FastIO;

    sieve();

    ll tc, tcase = 0, n;

    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        ll ans = fun(n)-1;
        printf("Case %lld: %lld\n", ++tcase, ans);
    }

    return 0;
}
