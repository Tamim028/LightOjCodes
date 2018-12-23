#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
typedef long long ll;

vector<int> graph[105];
vector<int> path;
int vis[105];

void dfs(int x){
    vis[x]=1;
    path.push_back(x);
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!vis[y]){
            dfs(y);
        }
    }
}
void clr(){
    memset(vis,0,sizeof(vis));
    for(int i=0; i<=101; i++){
        graph[i].clear();
    }
    path.clear();
}

int main()
{

    int tc,tcase=0,n,x,y,d;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        map< pair<int,int> , int > mp;
        for(int i=1; i<=n; i++){
            scanf("%d %d %d", &x, &y, &d);
            graph[x].push_back(y);
            graph[y].push_back(x);
            mp[make_pair(x,y)]=d;
        }
        memset(vis, 0, sizeof(vis));
        dfs(1);
        int ans1=0, ans2=0;
        path.push_back(path[0]);
        for(int i=1; i<path.size(); i++){
            int x=path[i-1];
            int y=path[i];
            if(mp[make_pair(x,y)]==0){
                ans1 += mp[make_pair(y,x)];
                //mp[make_pair(x,y)]=mp[make_pair(y,x)];
            }
        }
        for(int i=path.size()-2; i>=0; i--){
            int x=path[i+1];
            int y=path[i];
            if(mp[make_pair(x,y)]==0){
                ans2 += mp[make_pair(y,x)];
                //mp[make_pair(x,y)]=mp[make_pair(y,x)];
            }
        }
        ans1 = min(ans1, ans2);
        printf("Case %d: %d\n", ++tcase, ans1);
        clr();
    }


    return 0;
}

