#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int N, M;
int board[8][8];
int replace_board[8][8];

int visited[9][9];
int max_cnt = -2134567890;

struct coord {
    int x;
    int y;
};


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 벽 세개를 두는 모든 경우의 수에서 안전구역 개수 세기
// 벽 세개를 두고, 해당 보드에서 bfs 수행 후 안전구역 개수 세기
// 보드 초기화 반복


void bfs() {
    
    int afterSpread[8][8];

    // 벽 세워진 상태에서 퍼져나가기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            afterSpread[i][j] = replace_board[i][j];
        }
    }

    queue<coord> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (afterSpread[i][j] == 2) q.push({ i,j });
        }
    }

    
    while (!q.empty()) {
        coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            if (afterSpread[nx][ny] == 0) {
                afterSpread[nx][ny] = 2;
                q.push({ nx,ny });
            }
            
        }
        
    }

    int temp_cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (afterSpread[i][j] == 0) temp_cnt++;
        }
    }

    if (temp_cnt > max_cnt) {
        max_cnt = temp_cnt;
    }
}

void makeWall(int level) {
    if (level == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (replace_board[i][j] == 0) {

                replace_board[i][j] = 1;
                makeWall(level + 1);
                replace_board[i][j] = 0;
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] == 0) {

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        replace_board[i][j] = board[i][j];
                    }
                }
                replace_board[x][y] = 1;
                makeWall(1);
                replace_board[x][y] = 0;
            }
        }
    }
    
    cout << max_cnt;
    
}