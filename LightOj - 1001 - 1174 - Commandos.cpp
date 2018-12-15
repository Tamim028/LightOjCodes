#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

vector< int > graph[1005];
bool visited[1005];
int level[1005];
int mp[1005];

void BFS( int sx, int nodes ){

    //cout << "here\n";
    int i, j, x, y;
    for( i = 0; i <= nodes; i++ ){
        visited[i] = 0;
        level[i]   = 100000;
    }
    queue< int > q;
    visited[sx] = 1;
    level[sx]   = 0;

    q.push(sx);
    //cout << "here\n";

    while( !q.empty() ){
        x = q.front();
        q.pop();

        for( i = 0; i < graph[x].size(); i++ ){
            y = graph[x][i];
            if( visited[y] == 0 ){

                visited[y] = 1;
                q.push(y);

                if( level[x] + 1 < level[y] ){
                    level[y] = level[x] + 1;
                }
            }
        }
    }
    for( i = 0; i <= nodes; i++ ){
        mp[i] = level[i];
        //cout << "Level: " << mp[i] << endl;
    }

}

int BFS( int sx, int dx, int nodes ){

    if( sx == dx ){
        return 0;
    }

    int i, j, x, y;
    for( i = 0; i <= nodes; i++ ){
        visited[i] = 0;
        level[i]   = 100000;
    }
    queue< int > q;
    visited[sx] = 1;
    level[sx]   = 0;

    q.push(sx);
    while( !q.empty() ){
        x = q.front();
        q.pop();

        for( i = 0; i < graph[x].size(); i++ ){
            y = graph[x][i];
            if( visited[y] == 0 ){
                if( level[x] + 1 < level[y] ){
                    visited[y] = 1;
                    q.push(y);
                    level[y] = level[x] + 1;
                    if( y == dx ){
                        return level[y];
                    }
                }
            }
        }
    }

}

int main() {

    int T, test, n, nodes, edges, i, j, x, y, src, des, mx;

    cin >> T;
    for( test = 1; test <= T; test++ ){
        cin >> nodes;
        cin >> edges;
        for( i = 1; i <= edges; i++ ){
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin >> src >> des;

        BFS( src, nodes );
        mx = -1;
        for( i = 0; i < nodes; i++ ){
            x = BFS( i, des, nodes );
            if( mp[i] + x > mx ){
                mx = mp[i]+x;
            }
        }
        cout << "Case " << test << ": " << mx << endl;
        for( i = 0; i <= nodes; i++ ){
            mp[i] = 0;
            graph[i].clear();
        }
    }

    return 0;
}






