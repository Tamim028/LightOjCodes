#include<bits/stdc++.h>
using namespace std;

#define MAXS 100000

int main()
{

    //freopen("E:\\input.txt", "r", stdin);
    //freopen("E:\\output.txt", "w", stdout);

    int tc, tcase = 0, n, m, Lsz, Rsz,x;
    vector<int> v;
    string src;
    string push_LEFT = "pushLeft";
    string push_RIGHT = "pushRight";
    string pop_LEFT = "popLeft";
    string Pop_RIGHT = "popRight";

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        printf("Case %d:\n", ++tcase);
        while(m--){
            cin >> src;
            int lenn = v.size();
            if( src == push_LEFT ){
                cin >> x;
                if( lenn >= n  ){
                    printf("The queue is full\n");
                }
                else{
                    v.insert(v.begin(), x);
                    printf("Pushed in left: %d\n", x);
                }

            }
            else if( src == push_RIGHT ){
                cin >> x;
                if( lenn >= n  ){
                    printf("The queue is full\n");
                }
                else{
                    v.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
            }
            else if( src == pop_LEFT ){
                if( lenn > 0 ){
                    printf("Popped from left: %d\n", v[0]);
                    v.erase(v.begin());
                }
                else{
                    printf("The queue is empty\n");
                }
            }
            else{
                if( lenn > 0 ){
                    printf("Popped from right: %d\n", v[lenn-1]);
                    v.pop_back();
                }
                else{
                    printf("The queue is empty\n");
                }
            }
        }
        v.clear();
    }
    return 0;
}

