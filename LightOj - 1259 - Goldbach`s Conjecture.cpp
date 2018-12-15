#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
typedef long long int ll;

bool mark[MAX+5];
ll prime[700000], cnt = 0;

void sieve( int mx ){

    ll i, j;

    for( i = 4; i <= mx; i+=2 ){
        mark[i] = 1;
    }
    mark[0] = 1;
    mark[1] = 1;

    prime[1] = 2;
    cnt = 1;

    for( i = 3; i <= mx; i+=2 ){
        if( mark[i] == 0 ){
            prime[++cnt] = i;
            for( j = i*i; j <= mx; j+=2*i ){
                mark[j] = 1;
            }
        }
    }

}




int main(){

    sieve( MAX );

    ll T, i, j, x, temp, howMany;
    ll n;

     scanf("%lld", &T);
    for( i = 1; i <= T; i++ ){
        scanf("%lld", &n);
        howMany = 0;
        for( x = 1; prime[x] <= n/2; x++ ){
            temp = n - prime[x];
            if( mark[temp] == 0 ){
                howMany++;
            }
        }
        printf("Case %lld: %lld\n", i, howMany);
    }

       return 0;
}
