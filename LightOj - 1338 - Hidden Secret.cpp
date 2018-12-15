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


    _FastIO;

    int tc, tcase = 0;

    cin >> tc;
    cin.ignore();
    while(tc--){
        int aa[29], bb[29];
        string a, b;
        getline(cin, a);
        getline(cin, b);
        //cout << a << endl;
        //cout << b << endl;
        //getchar();
        //cout << "Here" << endl;
        for(int i = 0; i < 27; i++){
            aa[i] = bb[i] = 0;
        }
        for(int i = 0; i < a.size(); i++){
            if(a[i] == ' ' ){
                continue;
            }
            if(isupper(a[i])){
                a[i] = tolower(a[i]);
            }
            int id = a[i]-96;
            aa[id]++;
        }
        for(int i = 0; i < b.size(); i++){
            if(b[i] == ' ' ){
                continue;
            }
            if(isupper(b[i])){
                b[i] = tolower(b[i]);
            }
            int id = b[i]-96;
            bb[id]++;
        }
        int ans = 1;
        for(int i = 1; i <= 26; i++){
            if(aa[i] != bb[i]){
                ans = 0;
                break;
            }
        }
        if(ans == 1){
            printf("Case %d: Yes\n", ++tcase);
        }
        else{
            printf("Case %d: No\n", ++tcase);
        }
        //*/
    }

    return 0;
}





