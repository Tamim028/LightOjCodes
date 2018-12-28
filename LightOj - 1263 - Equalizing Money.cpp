#include<bits/stdc++.h>
using namespace std;

#define MAXS 100000
#define MOD 1000000007 //9
#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
#define all(v) v.begin(),v.end()
typedef long long ll;

int a[1005], vis[1005], ans, avg, people, money;
vector<int>graph[1005];

void clr(int n){
    for(int i=1; i<=n+1; i++){
        vis[i]=0;
        graph[i].clear();
    }
}

void dfs(int x){
    vis[x]=1;
    money += a[x];
    people++;
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(vis[y]==0){
            dfs(y);
        }
    }
    return;
}

int main()
{

    _FastIO;

    int tc,tcase=0,n,m;

    cin>>tc;
    while(tc--){
        cin>>n>>m;
        clr(n);
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        for(int i=1; i<=m; i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        ans=1;
        avg=-1;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                people=0;
                money = 0;
                dfs(i);
                //cout<<money << " p: " << people<<endl;
                if(money%people == 1){
                    ans=0;
                    break;
                }
                int tm_avg = money/people;
                if(avg==-1){
                    avg=tm_avg;
                }
                else if(avg!=tm_avg){
                    ans=0;
                    break;
                }
            }
            if(ans==0){
                break;
            }
        }
        if(ans==1){
            cout<<"Case " <<++tcase<< ": Yes\n";
        }
        else{
            cout<<"Case " <<++tcase<< ": No\n";
        }
    }

    return 0;
}








