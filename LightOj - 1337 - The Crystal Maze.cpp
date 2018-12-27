#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
#define all(v) v.begin(),v.end()
typedef long long ll;

int tc, tcase=0, row, col, qu, vis[505][505], ans[505][505];
int fx[] = {0, 0,-1, 1};
int fy[] = {1,-1, 0, 0};
string grid[505];

void clr(){
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    for(int i=0; i<=row; i++){
        grid[i].clear();
    }
}

bool isValid(int x, int y){
    if(x>=0 && x<row && y>=0 && y<col && vis[x][y]==0 && grid[x][y]!='#'){
        return 1;
    }
    return 0;
}

void bfs(int sx, int sy){
    queue<int> q;
    queue< pair<int,int> > qq;
    q.push(sx);
    q.push(sy);
    vis[sx][sy]=1;
    int cnt=0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        if(grid[x][y]=='C'){
            cnt++;
        }
        qq.push( make_pair(x,y) );
        for(int i=0; i<4; i++){
            int xx = fx[i]+x;
            int yy = fy[i]+y;
            if(isValid(xx,yy)){
                vis[xx][yy]=1;
                q.push(xx);
                q.push(yy);
            }
        }
    }
    while(!qq.empty()){
        pair<int,int> pi = qq.front(); qq.pop();
        ans[pi.first][pi.second]=cnt;
    }
    return;
}

void solve(){

    for(int i=0; i<row; i++){
        for(int k=0; k<col; k++){
            if(grid[i][k]=='#'){
                ans[i][k]=0;
                vis[i][k]=1;
                continue;
            }
            if(vis[i][k]==0){
                bfs(i,k);
            }
        }
    }
}

int main()
{

    _FastIO;

    cin>>tc;
    while(tc--){
        clr();
        cin>>row>>col>>qu;
        for(int i=0; i<row; i++){
            cin>>grid[i];
        }
        solve();
        printf("Case %d:\n", ++tcase);
        while(qu--){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            printf("%d\n", ans[x][y]);
        }
    }

    return 0;
}








