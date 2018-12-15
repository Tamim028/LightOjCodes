#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MAXS 1000000
#define pLL pair<ll, ll>

vector< pair< int, pair<int, int> > > v;
int nodes, edges, x, y, w;
int par[505];
vector<int> graph[501];
int cost[501][501];

int search_par( int r ){

    if( par[r] == r ){
        return r;
    }
    else return par[r] = search_par( par[r] );

}

void union_find(int x, int y, int weight){

    int u = search_par(x);
    int v = search_par(y);

    if( u == v ){
        return;
    }
    else{
        par[u] = v;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x][y] = cost[y][x] = weight;
        return;
    }

}

void mst(){

    sort(v.begin(), v.end());
    int lenn = v.size();

    for( int i = 0; i < nodes; i++ ){
        par[i] = i;
    }

    for( int i = 0; i < lenn; i++ ){
        pair<int, int> pp;
        pp = v[i].second;

        int weight = v[i].first;
        int u = pp.first;
        int v = pp.second;
        //cout << "u: " << u << " v: " << v << " w: " << weight << endl;

        union_find(u, v, weight);
    }


}

bool visited[505];
int dest, maxx[505];

int BFS(int src){
    for(int i = 0; i < nodes; i++){
        visited[i] = 0;
        maxx[i] = -1;
    }
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while( !q.empty() ){
        int x = q.front(); q.pop();
        for( int i = 0; i < graph[x].size(); i++ ){
            int y = graph[x][i];
            if( visited[y] == 0 ){
                visited[y] = 1;
                q.push(y);
                maxx[y] = max(cost[x][y], maxx[x]);
            }
        }
    }
    return maxx[dest];
}

int main(){

    int tc, tcase = 0;

    scanf("%d", &tc);
    while(tc--){
        //cin >> nodes >> edges;
        memset(cost, 0, sizeof(cost));
        scanf("%d %d", &nodes, &edges);
        for( int i = 1; i <= edges; i++ ){
            cin >> x >> y >> w;
            pair<int, int> pp;
            pp = make_pair(x, y);
            v.push_back( make_pair( w, pp) );
        }
        scanf("%d", &dest);
        mst();
        printf("Case %d:\n", ++tcase);
        for( int i = 0; i < nodes; i++ ){
            //memset(visited, 0, sizeof(visited));
            if( i == dest ){
                printf("0\n");
            }
            else{
                int ans = BFS(i);
                if( ans == -1 ){
                    printf("Impossible\n");
                }
                else printf("%d\n", ans);
            }
        }
        v.clear();
        for(  int i = 0; i < nodes; i++ ){
            graph[i].clear();
            visited[i] = 0;
        }
    }

    return 0;
}
