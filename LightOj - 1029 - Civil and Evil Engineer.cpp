#include<bits/stdc++.h>
using namespace std;

#define MAXS 100000

int tc, tcase = 0, n;
vector< pair<int, pair<int, int> > > v;
vector< pair<int, pair<int, int> > > vec;
int par[105];
int ansOne, ansTwo;

int par_find(int r){
    if( par[r] == r ){
        return r;
    }
    else return par[r] = par_find(par[r]);
}

void union_find(int x, int y, int w){
    int u = par_find(x);
    int v = par_find(y);

    if( u == v ){
        return;
    }
    else{
        par[u] = v;
        ansOne += w;
        return;
    }
}

void mst(){
    for( int i = 0; i <= n; i++ ){
        par[i] = i;
    }
    sort(v.begin(), v.end());
    int lenn = v.size();
    for( int i = 0; i < lenn; i++ ){
        pair<int, int> pp1;
        pp1 = v[i].second;
        int x = pp1.first;
        int y = pp1.second;
        int w = v[i].first;

        union_find(x, y, w);
    }
}

void union_find_2nd(int x, int y, int w){

    int u = par_find(x);
    int v = par_find(y);

    if( u == v ){
        return;
    }
    else{
        par[u] = v;
        ansTwo += w;
        return;
    }
}

void mst2nd(){
    for( int i = 0; i <= n; i++ ){
        par[i] = i;
    }
    sort(vec.begin(), vec.end());
    int lenn = vec.size();
    for( int i = lenn-1; i >= 0; i-- ){
        pair<int, int> pp1;
        pp1 = vec[i].second;
        int x = pp1.first;
        int y = pp1.second;
        int w = vec[i].first;

        union_find_2nd(x, y, w);
    }
}

int main()
{
    int x, y, w;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        while( scanf("%d %d %d", &x, &y, &w) && (x || y || w) ){

            pair<int, int> pp1;
            pp1 = make_pair(x, y);
            v.push_back(make_pair(w, pp1));
            vec.push_back(make_pair(w, pp1));
        }
        ansOne = 0;
        ansTwo = 0;
        mst();
        mst2nd();

        if( (ansOne+ansTwo) % 2 == 0 ){
            printf("Case %d: %d\n", ++tcase, (ansOne+ansTwo)/2);
        }
        else{
            printf("Case %d: %d/2\n", ++tcase, (ansOne+ansTwo) );
        }
        vec.clear();
        v.clear();
    }

    return 0;
}

