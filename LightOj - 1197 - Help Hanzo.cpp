#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

bool mark[100005];
LL prime[100005], cnt;

void sieve(){
    LL i, j, mx = 100000;

    for(i=4; i<=mx; i+=2){
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
bool ck[100005];
LL answer( LL low, LL high ){

    LL i, j, limit;
    LL start, x;
    if( low > high ){
        swap(low, high);
    }
    limit = sqrt( (double) high );
    ck[0] = 1;
    for( i = 1; prime[i] <= limit; i++ ){
        start = ( low / prime[i] ) * prime[i];
        if( start < low ){
            start += prime[i];
        }
        if( start == prime[i] ){
            start += prime[i];
        }
        for( j = start; j <= high; j+=prime[i] ){
            ck[j-low+1] = 1;
        }
    }
    x = 0;
    for( i = 1; i <= high-low+1; i++ ){
        if( ck[i] == 0 ){
            x++;
        }
        ck[i] = 0;
    }
    if( low == 1 ){
        x -= 1;
    }
    return x;
}

int main(){

    LL T, test, low, high, ans;

    sieve();

    cin >> T;
    for( test = 1; test <= T; test++ ){
        cin >> low >> high;
        ans = answer(low, high);
        cout << "Case " << test << ": " << ans << endl;
    }

    return 0;
}
