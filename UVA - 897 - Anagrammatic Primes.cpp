#include<bits/stdc++.h>
using namespace std;

#define MAXS 1000
typedef long long int ll;
typedef unsigned long long int ull;

int arr[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

int main()
{

    ll n;
    while(scanf("%lld",  &n) && n ){
        ll num = n;
        ll dig = 0;
        while(num){
            num = num/10;
            dig++;
        }
        //cout << dig << endl;
        bool flag = 0;
        for(int i = 0; i < 22; i++){
            if( arr[i] > n && arr[i] < pow(10, dig) ){
                printf("%lld\n", arr[i]);
                flag = 1;
                break;
            }
        }
        if( flag == 0 ){
            printf("0\n");
        }
    }

    return 0;
}
