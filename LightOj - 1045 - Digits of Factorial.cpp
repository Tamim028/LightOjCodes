#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXS 5000003
#define eps -0.000000001

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

vector< pair<int, double> > vec;

int factorialDigit(int n, int b){

    double x = vec[n].second;
    double y = log10(b);
    //cout<<"x: " << mp[x] << " y: " << y << endl;
    int ans;
    if(b == 10){
        ans = x+1;
        //return ans;
    }
    else{
        ans = (int)(x/y) + 1;
    }
    //cout<<"res: " << res << endl;
    return ans;
}

int main()
{

    int tc, tcase = 0, n, b;

    double x = 0;
    vec.push_back(make_pair(0,0));
    for(int i = 1; i <= 1000001; i++){
            x += log10(i);
            vec.push_back(make_pair(i, x));
    }

    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &b);
        int ans = factorialDigit(n, b);
        printf("Case %d: %d\n", ++tcase, ans);
    }
    return 0;
}
