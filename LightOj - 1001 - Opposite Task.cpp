#include<bits/stdc++.h>
using namespace std;

/// ACCEPTED

int main()
{

    int T, i, j, n, flag;

    scanf("%d", &T);
    while( T-- ){
        scanf("%d", &n);
        for( i = 10; i >= 0; i-- ){
            flag = 0;
            for( j = 0; j <= 10; j++ ){
                if( i + j == n ){
                    printf("%d %d\n", i, j);
                    flag = 1;
                    break;
                }
            }
            if( flag == 1 ){
                break;
            }
        }
    }

    return 0;
}





