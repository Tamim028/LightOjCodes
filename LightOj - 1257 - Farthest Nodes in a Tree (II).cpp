#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
#define all(v) v.begin(),v.end()
typedef long long ll;

int vis[30005], ans[30005], ans1[30005], node, tc, tcase=0;
vector<int> graph[30005];
map< pair<int,int>, int > mp;

void clr(){
    mp.clear();
    for(int i=0; i<=node; i++){
        ans[i]=0;
        vis[i]=0;
        graph[i].clear();
    }
}

int bfs(int p, int ck){
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(p);
    vis[p]=1;
    if(ck!=2){
        ans[p]=0;
    }
    if(ck==2){
        ans1[p]=0;
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(vis[y]==0){
                vis[y]=1;
                if(ck!=2){
                    ans[y]= ans[x]+mp[make_pair(x,y)];
                }
                if(ck==2){
                    ans1[y] =ans1[x]+mp[make_pair(x,y)];
                }
                q.push(y);
            }
        }
    }
    if(ck!=0){
        return 0;
    }
    int tm, mx=-1;
    for(int i=0; i<node; i++){
        if(ans[i]>mx){
            mx=ans[i];
            tm=i;
        }
    }
    return tm;
}

int main()
{

    _FastIO;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &node);
        clr();
        for(int i=1; i<node; i++){
            int x,y,w;
            scanf("%d %d %d", &x, &y, &w);
            graph[x].push_back(y);
            graph[y].push_back(x);
            mp[make_pair(x,y)]=w;
            mp[make_pair(y,x)]=w;
        }
        int a = bfs(0, 0);
        int b = bfs(a, 0);
        int t;
        t = bfs(a, 1);
        t = bfs(b, 2);
        printf("Case %d:\n", ++tcase);
        for(int i=0; i<node; i++){
            int x = max(ans[i], ans1[i]);
            printf("%d\n", x);
        }
        //cout<<"a: " << a << " b: " << b << endl;
    }

    return 0;
}








