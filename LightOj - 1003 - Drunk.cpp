#include<bits/stdc++.h>
using namespace std;

/// Accepted ///

int main()
{

    int T, i, j, k, n, flag;
    char before[10001][20], after[10001][20];

    scanf("%d", &T);
    for( i = 1; i <= T; i++ ){
        scanf("%d", &n);
        flag = 1;
        for( j = 1; j <= n; j++ ){
            scanf("%s %s", before[j], after[j]);
            if( flag == 1 ){
                for( k = 1; k <= j; k++ ){
                    if( strcmp( before[j] , after[k] ) == 0 && strcmp( after[j] , before[k] ) == 0 ){
                        flag = 0;
                        break;
                    }
                }
            }


        }
        if( flag == 1 ){
            printf("Case %d: Yes\n", i);
        }
        else{
            printf("Case %d: No\n", i);
        }
    }

    return 0;
}

