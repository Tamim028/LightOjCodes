#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXS 5000003
#define M 998244353
#define eps -0.000000001

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

struct info{
    char name[25];
    int area;
};

int main()
{


    //_FastIO;

    int tc, tcase = 0, n;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        char s[25], x[25], y[25];
        info arr[205];
        int a, b, c;
        for(int i = 1; i <= n; i++){
            scanf("%s %d %d %d", s, &a, &b, &c);
            //arr[i].name = s;
            strcpy(arr[i].name, s);
            arr[i].area = a*b*c;
        }
        int ck = 0;
        for(int i = 2; i <= n; i++){
            if(arr[i].area != arr[1].area){
                ck = 1;
                break;
            }
        }
        if(ck){
            int mx = 0;
            int mn = 10000000;
            char mxName[25], mnName[25];
            for(int i = 1; i <= n; i++){
                if(arr[i].area > mx){
                    mx     = arr[i].area;
                    strcpy(mxName, arr[i].name);
                    //mxName = arr[i].name;
                }
                if(arr[i].area < mn){
                    mn     = arr[i].area;
                    strcpy(mnName, arr[i].name);
                    //mnName = arr[i].name;
                }
            }
            printf("Case %d: %s took chocolate from %s\n", ++tcase, mxName, mnName);
        }
        else{
            printf("Case %d: no thief\n", ++tcase);
        }
    }


    return 0;
}














