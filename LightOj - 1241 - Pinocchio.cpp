#include<bits/stdc++.h>
using namespace std;

#define MAXS 1000
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{

    int tc, tcase = 0, n, arr[1005];

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        arr[0] = 2;
        int ans = 0;
        for( int i = 1; i <= n; i++ ){
            int x = arr[i]-arr[i-1];
            for(int k = 5; k >= 1; k--){
                if( x >= k  ){
                    ans += ceil( (x*1.0)/(k*1.0) );
                    break;
                }
            }
        }
        printf("Case %d: %d\n", ++tcase, ans);
    }

    return 0;
}

