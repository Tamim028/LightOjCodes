#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAX  LONG_LONG_MAX
#define Pii acos(-1)
typedef long long ll;


int main()
{

    double r1,r2,h,p;
    int tc, tcase=0;
    scanf("%d", &tc);
    while(tc--){
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
        //cin>>r1>>r2>>h>>p;
        double r = r1-(((r1-r2)/h)*(h-p));
        double total = (Pii/3.0)*p*(r*r+r2*r2+r*r2);
        printf("Case %d: %.7lf\n", ++tcase, total);
        //cout.precision(12);
        //cout<<"Case "<< ++tcase << ": " << total<<endl;
    }

    return 0;
}





