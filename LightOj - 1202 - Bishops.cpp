#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXS 5000003
#define M 998244353
#define eps -0.000000001

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

int main()
{


    //_FastIO;

    int tc, tcase = 0;

    scanf("%d", &tc);
    while(tc--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int xx = abs(x1-x2);
        int yy = abs(y1-y2);
        if(xx == yy){
            printf("Case %d: 1\n", ++tcase);
        }
        else{
            if(xx%2 == 0 && yy%2 == 0){
                printf("Case %d: 2\n", ++tcase);
            }
            else if(xx%2 != 0 && yy%2 != 0){
                printf("Case %d: 2\n", ++tcase);
            }
            else{
                printf("Case %d: impossible\n", ++tcase);
            }
        }
    }

    return 0;
}















