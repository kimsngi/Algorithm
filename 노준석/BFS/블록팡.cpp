#include <iostream>

#include <string.h>

#include <string>

#include <stack>

#include <vector>

#include <queue>

#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct coord {
    int x;
    int y;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, k;
int board[101][10];
int visited[101][10]; // 방문 체크
int pang_flag[101][10]; // 터질 지역인지 아닌지 체크

queue<coord> q;

int temp_size = 1;
bool pangFlag = true;

void bfs(int x, int y, int num) {
    vector<coord> path; // 탐색한 영역 저장할 path vector
    q.push({ x,y });
    visited[x][y] = 1;
    path.push_back({ x,y });

while (!q.empty()) {
    coord now = q.front(); q.pop();
    
    for (int i = 0; i < 4; i++) {
        int nx = now.x + dx[i];
        int ny = now.y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= 10) continue; // 범위 가지치기
        if (visited[nx][ny]) continue; // 방문 가지치기
        if (board[nx][ny] == 0 || (board[nx][ny] != num)) continue; // 같은 숫자일때만, 0아닐때만 탐색

        visited[nx][ny] = 1;
        q.push({ nx,ny });
        temp_size++;
        path.push_back({ nx,ny });
    }
}
// 탐색을 다 하고 난 뒤, 사이즈가 K 이상이면? => 해당 영역 모두 터트려도 됨
if (temp_size >= k) {
    for (int i = 0; i < path.size(); i++) {
        board[path[i].x][path[i].y] = 0;
    }
}
}

void initVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            visited[i][j] = 0;
        }
    }
}

queue<coord> checkQueue;
int checkMaxSize = -2134567890;
int tempCheckSize = 1;

void checkMaxBlock(int x, int y,int num) {
    checkQueue.push({ x,y });
    visited[x][y] = 1;

while (!checkQueue.empty()) {
    coord now = checkQueue.front(); checkQueue.pop();

    for (int i = 0; i < 4; i++) {
        int nx = now.x + dx[i];
        int ny = now.y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= 10) continue; // 범위 가지치기
        if (visited[nx][ny]) continue; // 방문 가지치기
        if (board[nx][ny] == 0 || (board[nx][ny] != num)) continue; // 같은 숫자일때만, 0아닐때만 탐색

        visited[nx][ny] = 1;
        checkQueue.push({ nx,ny });
        tempCheckSize++;
    }
}
if (tempCheckSize > checkMaxSize) checkMaxSize = tempCheckSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

// 1~9까지의 블록 입력
for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < row.size(); j++) {
        board[i][j] = row[j] - '0';
    }
}

// pangFlag : 앞으로 더 터질 블록이 남아있는지 판별
while (pangFlag) {
    initVisited();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            // 1. bfs 탐색해서, 크기가 K 이상이면 터트리기

            if (board[i][j] == 0) continue; // 0이면 가지치기
            if (visited[i][j]) continue; // 방문했으면 가지치기

            int num = board[i][j]; // 해당 좌표의 숫자, 이 숫자와 동일한 부분만 탐색한다
            bfs(i, j, num);
            temp_size = 1; // 탐색 다 하고나서 temp_size 초기화
        }
    }

    // 2. 터지고 나서, 중력에 의해 모든 블록들 아래로
    for (int i = n - 1; i > -1; i--) {
        for (int j = 9; j > -1; j--) {
            if (board[i][j] == 0) {
                for (int h = i; h > -1; h--) {
                    if (board[h][j] != 0) {
                        swap(board[i][j], board[h][j]);
                        break;
                    }
                }
            }
        }
    }

    // 남은 블록들을 모두다 다시 bfs해서 영역의 최대 넓이가 k보다 작으면? 더이상 터트릴 게 없다
    // pangFlag 변경
    initVisited();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {

            if (board[i][j] == 0) continue; // 0이면 가지치기
            if (visited[i][j]) continue; // 방문했으면 가지치기

            int num = board[i][j]; // 해당 좌표의 숫자, 이 숫자와 동일한 부분만 탐색한다
            checkMaxBlock(i, j, num);
            tempCheckSize = 1; // 탐색 다하고 나서 초기화
        }
    }

    // 만약 남아있는 블록의 크기가 k보다 작은것들만 있다면, 그대로 종료
    if (checkMaxSize < k) {
        break;
    }

    checkMaxSize = -2134567890;
    tempCheckSize = 1;
}


for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
        cout << board[i][j];
    }
    cout << "\n";
}
}