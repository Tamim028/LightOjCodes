#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MAXS 10000000
#define pLL pair<ll, ll>

int nodes, edges, cost, cnt;
vector<int> graph[105];
vector<pair<int, pair<int, int> > > v;
int par[105];

int find_par(int r){
    if( par[r] == r ){
        return r;
    }
    else return par[r] = find_par(par[r]);
}

void union_find(int x, int y, int w){
    int u = find_par(x);
    int v = find_par(y);

    if( u == v ){
        return;
    }
    else{
        par[u] = v;
        cost += w;
        cnt++;
        return;
    }
}

void mst(){

    for(int i = 1; i <= nodes; i++){
        par[i] = i;
    }
    sort(v.begin(), v.end());
    int lenn = v.size();
    for(int i = 0; i < lenn; i++){
        pair<int, int> pp1;
        pp1 = v[i].second;

        int x = pp1.first;
        int y = pp1.second;
        int w = v[i].first;

        if( cnt > nodes-1 ){
            return;
        }
        union_find(x, y, w);
    }
    return;

}

int main(){

    char src1[55], src2[55];
    int tc, tcase = 0, x, y, w;

    scanf("%d", &tc);
    while(tc--){
        nodes = 0;
        scanf("%d", &edges);
        map<string, int> mp;
        while(edges--){
            scanf("%s %s %d", src1, src2, &w);
            if( mp[src1] == 0 ){
                mp[src1] = ++nodes;
            }
            if( mp[src2] == 0 ){
                mp[src2] = ++nodes;
            }
            x = mp[src1]; y = mp[src2];
            pair<int, int> pp1;
            pp1 = make_pair(x, y);
            v.push_back(make_pair(w, pp1));
        }
        cost = 0;
        cnt  = 0;
        mst();
        //cout << "cnt: " << cnt << " nodes: " << nodes << endl;
        if( cnt < nodes-1 ){
            printf("Case %d: Impossible\n", ++tcase);
        }
        else printf("Case %d: %d\n", ++tcase, cost);
        v.clear();
        for(int i = 1; i <= nodes; i++){
            graph[i].clear();
        }

    }


    return 0;
}
