#include<bits/stdc++.h>
using namespace std;

#define MAX 100001

typedef long long int ll;
typedef unsigned long long int ull;

vector< int >grid[101];
int visited[1001], arr[1001];

void BFS( int src, int nodes, int des ){

    int i, j, u, v;

    for( i = 1; i <= nodes; i++ ){
        visited[i] = 0;
    }

      queue<int>q;

      visited[src] = 1;
      q.push( src );

      while( !q.empty() ){

         u = q.front();
         q.pop();
         for( i = 0; i < grid[u].size(); i++ ){

            v = grid[u][i];

            if( visited[v] == 0 ){

                visited[v] = 1;
                q.push(v);

            }
         }

      }
      for( i = 1; i <= nodes; i++  ){
        if( visited[i] == 1 ){
            arr[i] = 1;
        }
        else arr[i] = 0;
      }

}

int main(){

    int T, persons, cityPersons[101], nodes, edges, i, j, test, x, y, cnt;

    scanf("%d", &T);
    for( test = 1; test <= T; test++ ){
        scanf("%d %d %d", &persons, &nodes, &edges );
        for( i = 1; i <= persons; i++ ){
            scanf("%d", &cityPersons[i]);
        }
        for( i = 1; i <= edges; i++ ){
            scanf("%d %d", &x, &y);
            grid[x].push_back(y);
        }
        for( i = 1; i <= persons; i++ ){
            BFS( cityPersons[i], nodes, 4 );
        }
        cnt = 0;
        for( i = 1; i <= nodes; i++ ){
            if( arr[i] == 1 ){
                cnt++;
                arr[i] = 0;
            }
        }
        printf("Case %d: %d\n", test, cnt);

        for( i = 1; i <= nodes; i++ ){
               grid[i].clear();
        }

    }

    return 0;
}








