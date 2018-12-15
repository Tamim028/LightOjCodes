#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

int a, b, c, d, e, f;
LL dp[10005];
int x = 0;
int fn( int n ) {

    if( n == 0 ) return a % 10000007;
    if( n == 1 ) return b % 10000007;
    if( n == 2 ) return c % 10000007;
    if( n == 3 ) return d % 10000007;
    if( n == 4 ) return e % 10000007;
    if( n == 5 ) return f % 10000007;


    if( dp[n] != -10000 ){
        return dp[n];
    }

    return dp[n] =  ( fn(n-1)  + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;

}
int main() {
    int n, caseno = 0, cases;
    LL ans;

    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        for( int i = 0; i <= n+1; i++ ){
            dp[i] = -10000;
        }
        ans = fn(n);
        printf("Case %d: %lld\n", ++caseno, ans);
    }
    return 0;
}







