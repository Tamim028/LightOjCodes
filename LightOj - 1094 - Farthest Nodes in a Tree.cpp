#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS (ll)1e18

#define _FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()

vector<int>graph[30005];
map<pair<int,int>,int> mp;
int vis[30005], cst[30005], mxx, nod;

void dfs(int x){
    if(vis[x]){
        return;
    }
    vis[x] = 1;
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!vis[y]){
            cst[y] = cst[x]+ mp[make_pair(x,y)];
            if(cst[y]>mxx){
                mxx = cst[y];
                nod = y;
            }
            dfs(y);
        }
    }
    return;
}

int main()
{

    int tc, tcase = 0, n, x, y, w;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i=0; i<n-1; i++){
            scanf("%d %d %d", &x, &y, &w);
            graph[x].push_back(y);
            graph[y].push_back(x);
            mp[make_pair(x,y)]=w;
            mp[make_pair(y,x)]=w;
        }
        mxx = 0;
        dfs(0);
        memset(vis, 0, sizeof(vis));
        memset(cst, 0, sizeof(cst));
        mxx = 0;
        dfs(nod);
        printf("Case %d: %d\n", ++tcase, mxx);
        for(int i=0; i<=n; i++){
            graph[i].clear();
            vis[i] = 0;
            cst[i] = 0;
        }
        mp.clear();
    }

    return 0;
}
