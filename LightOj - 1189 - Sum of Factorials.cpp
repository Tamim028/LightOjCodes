#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAX  LONG_LONG_MAX
typedef long long ll;

int main()
{

    //_FastIO;

    ll v[25];
    v[0]=1;
    ll x=1;
    for(ll i=1; i<=20; i++){
        x*=i;
        v[i]=x;
    }
    ll tc, tcase=0, n;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        ll arr[30], k=0;
        for(ll i=20; i>=0; i--){
            if(n>=v[i]){
               arr[++k]=i;
               n-=v[i];
            }
        }
        if(n==0){
            printf("Case %lld: ", ++tcase);
            for(ll i=k; i>=1; i--){
                printf("%lld!", arr[i]);
                if((i-1)>=1){
                    printf("+");
                }
            }
            printf("\n");
        }
        else{
            printf("Case %lld: impossible\n", ++tcase);
        }
    }

    return 0;
}





