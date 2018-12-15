#include<bits/stdc++.h>
using namespace std;

long long int recurBinary( long long int n ){

    if( n == 0 ){
        return 0;
    }
    else{
        return n%2 + recurBinary( n / 2 );
    }

}
/// Time Limit exceeded ///
int main()
{

    long long int T, N, i, j, key, lock;

    scanf("%lld", &T);
    for( i = 1; i <= T; i++){
        scanf("%lld", &N);
        key = recurBinary(N);
        for( j = N+1; j < j+1; j++ ){
            lock = recurBinary( j );
            if( key == lock ){
                printf("Case %lld: %lld\n", i, j);
                break;
            }
        }
    }

    return 0;
}





