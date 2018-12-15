#include<bits/stdc++.h>
using namespace std;

#define MAX 100001

typedef long long int ll;
typedef unsigned long long int ull;

int grid[100][100], visited[100][100], level[100][100];
int fx[] = { 1, -1, 0,  0};
int fy[] = { 0,  0, 1, -1};

bool isValid( int x, int y, int row, int col ){

    if( x >= 0 && x < row && y >= 0 && y < col && grid[x][y] != 1 && visited[x][y] == 0 ){
        return 1;
    }
    return 0;

}

int BFS( int sx, int sy, int dx, int dy, int row, int col ){

    int i, j;

    for(i = 0; i < row; i++){
        for( j = 0; j < col; j++ ){
            visited[i][j] = 0;
            level[i][j] = MAX;
        }
    }

    queue<int>q;
    visited[sx][sy] = 1;
      level[sx][sy] = 0;

      q.push( sx ); q.push( sy );

      while( !q.empty() ){

        int x = q.front(); q.pop();
        int y = q.front(); q.pop();

        for( i = 0; i < 4; i++ ){
            int xx = x + fx[i];
            int yy = y + fy[i];

            if( isValid( xx, yy, row, col ) ){

                visited[xx][yy] = 1;
                q.push(xx); q.push(yy);

                if( level[x][y] + 1 < level[xx][yy] ){
                    level[xx][yy] = level[x][y] + 1;
                    if( xx == dx && yy == dy ){
                        return level[xx][yy];
                    }
                }
            }

        }

      }

}

int main(){

    int T, i, j, row, col, aax, aay, bbx, bby, ccx, ccy, dx, dy;
    int arr[5], maxx, test, lenn;
    char str[500];

    scanf("%d", &T);
    for( test = 1; test <= T; test++ ){

        scanf("%d %d\n", &row, &col);
        //getchar();

        for( i = 0; i < row; i++ ){
            for( j = 0; j < col; j++ ){
                grid[i][j] = 0;
            }
        }

        for( i = 0; i < row; i++ ){
            scanf("%s", str);
            lenn = strlen(str);

            for( j = 0; j < lenn; j++ ){
                if( str[j] == '#' || str[j] == 'm' ){
                    grid[i][j] = 1;
                }
                if( str[j] == 'a' ){
                    aax = i;
                    aay = j;
                }
                if( str[j] == 'b' ){
                    bbx = i;
                    bby = j;
                }
                if( str[j] == 'c' ){
                    ccx = i;
                    ccy = j;
                }
                if( str[j] == 'h' ){
                    dx = i;
                    dy = j;
                }

            }

        }

        arr[1] = BFS( aax, aay, dx, dy, row, col );
        arr[2] = BFS( bbx, bby, dx, dy, row, col );
        arr[3] = BFS( ccx, ccy, dx, dy, row, col );

        maxx = -1;
        for( i = 1; i <= 3; i++ ){
            if( arr[i] > maxx ){
                maxx = arr[i];
            }
        }
        printf("Case %d: %d\n",test, maxx );

    }

    return 0;
}







