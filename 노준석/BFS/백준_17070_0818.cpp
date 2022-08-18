#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct pipe {
    int x;
    int y;
    int type;
};

int N;
int board[16][16];
int visited[16][16];

// 가로, 세로, 대각선으로 놓여져있는지 체크??
// 0 : 가로, 1 : 세로, 2 : 대각선

// 놓여져있는 형태에 따른 다음번에 갈수 있는 위치 체크
int dx[3][3] = {
    {0,1,0},
    {1,1,0},
    {0,1,1}
};

int dy[3][3] = {
    {1,1,0},
    {0,1,0},
    {1,0,1}
};

queue<pipe> q;
int cnt = 0;

void bfs(pipe start) {
    q.push(start);

    while (!q.empty()) {
        visited[N - 1][N - 1] = 0;
        pipe now = q.front();
        q.pop();
        if (now.x == N - 1 && now.y == N - 1) {
            cnt++;
            continue;
        }

        switch (now.type) {
            // 현재 가로로 놓여있는 경우
            case 0:
                for (int i = 0; i < 3; i++) {
                    int nx = now.x + dx[0][i];
                    int ny = now.y + dy[0][i];

                    // 범위 벗어나면 가지치기
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    // 벽이면 가지치기
                    if (board[nx][ny] == 1) continue;
                    if (i == 2) continue;

                    visited[nx][ny] = 1;
                    
                    if (i == 0) q.push({ nx,ny,0 });
                    if (i == 1 && board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0) {
                        q.push({ nx,ny,2 });
                    }
                }

                break;
            // 현재 세로로 놓여있는 경우
            case 1:
                for (int i = 0; i < 3; i++) {
                    int nx = now.x + dx[1][i];
                    int ny = now.y + dy[1][i];

                    // 범위 벗어나면 가지치기
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    // 벽이면 가지치기
                    if (board[nx][ny] == 1) continue;
                    if (i == 2) continue;

                    visited[nx][ny] = 1;

                    if (i == 0) q.push({ nx,ny,1 });
                    // && !(nx == N - 1 && ny == N - 1)
                    if (i == 1 && board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0 ) {
                        q.push({ nx,ny,2 });
                    }
                    
                }
                break;
            // 현재 대각선으로 놓여있는 경우
            case 2:
                for (int i = 0; i < 3; i++) {
                    int nx = now.x + dx[2][i];
                    int ny = now.y + dy[2][i];

                    // 범위 벗어나면 가지치기
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    // 벽이면 가지치기
                    if (board[nx][ny] == 1) continue;

                    visited[nx][ny] = 1;

                    if (i == 0) q.push({ nx,ny,0 });
                    if (i == 1) q.push({ nx,ny,1 });
                    if (i == 2 && board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0) {
                        q.push({ nx,ny,2 });
                    }

                    
                }
                break;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    if (board[0][1] == 1 || board[N-1][N-1] == 1) {
        cout << 0;
        return 0;
    }
    

    // 현재 위치 : (0,1), type : 0(가로)
    //visited[0][1] = 1;
    bfs({ 0,1,0 });

    cout << cnt;
}