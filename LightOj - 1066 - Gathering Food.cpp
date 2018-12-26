#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
#define all(v) v.begin(),v.end()
typedef long long ll;

int fx[] = {1,-1, 0, 0};
int fy[] = {0, 0,-1, 1};
int n, tc, tcase=0, mx, vis[17][17], cnt[17][17];
string grid[17];

void clr(int n){
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n; i++){
        grid[i].clear();
    }
}

bool isValid(int x, int y, int now){
    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!='#' && vis[x][y]==0){
        if( isalpha(grid[x][y]) ){
            if( now+1 < (grid[x][y]-64) ){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int bfs(int sx, int sy, int now, int pos){
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<int> q;
    q.push(sx);
    q.push(sy);
    vis[sx][sy]=1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        //cout<<"x: " << x << " y: " << y << endl;
        for(int i=0; i<4; i++){
            int xx = x + fx[i];
            int yy = y + fy[i];
            if(isValid(xx, yy, now)){
                cnt[xx][yy] = cnt[x][y]+1;
                vis[xx][yy] = 1;
                q.push(xx);
                q.push(yy);
                if( (grid[xx][yy]-64)==(now+1) ){
                    return cnt[xx][yy];
                }
            }
        }
    }
    return -1;
}

int main()
{

    _FastIO;

    cin>>tc;
    while(tc--){
        cin>>n;
        clr(n);
        for(int i=0; i<n; i++){
            cin>>grid[i];
        }
        mx=0;
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                if(isalpha(grid[i][k])){
                    mx++;
                }
            }
        }
        ll ans=0, ck=1;
        for(int i=1; i<mx && ck; i++){
            for(int j=0; j<n && ck; j++){
                for(int k=0; k<n; k++){
                    if( (grid[j][k]-64)==i ){
                        int xb = bfs(j,k,i,1);
                        if(xb==-1){
                            ck=0;
                            break;
                        }
                        else{
                            ans+=xb;
                        }
                    }
                }
            }
        }
        if(ck){
            printf("Case %d: %d\n", ++tcase, ans);
        }
        else{
            printf("Case %d: Impossible\n", ++tcase);
        }
    }

    return 0;
}









