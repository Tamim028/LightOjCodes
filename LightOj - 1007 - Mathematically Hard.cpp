#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXS 5000003

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

ull phi[5000005];
//ull sum[5000005]; //for using sum array got Memory Limit Exceeded
bool mark[5000006];

void sieve(){

    for(ll i=2; i<=MAXS; i++){
        phi[i]=(ull)i;
    }
    for(ll i=4; i<=MAXS; i+=2){
        mark[i]=1;
        phi[i]/=2;
    }
    mark[1] = 1;
    phi[2]=(ull)1;
    for(ll i=3; i<=MAXS; i+=2){
        if(mark[i]==0){
            phi[i]=(ull)i-1;
            for(ll j=i+i; j<=MAXS; j+=i){
                mark[j]=1;
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    //sum[1] = 0;
    phi[1]=0;
    for(ll i=2; i<=MAXS; i++){
        //sum[i] = sum[i-1]+(phi[i]*phi[i]);
        ull x=phi[i];
        phi[i] = phi[i-1]+(x*x);
    }
}

int main()
{

    int tc, tcase = 0, x, y;
    memset(mark,0,sizeof(mark));
    sieve();
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &x, &y);
        //ull ans = sum[y]-sum[x-1];
        printf("Case %d: %llu\n", ++tcase, phi[y]-phi[x-1]);
    }

    return 0;
}
