#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int N, M;

int board[101][101];
int visited[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int max_x = MY_MAX;
int min_x = MY_MIN;
int max_y = MY_MAX;
int min_y = MY_MIN;

// 현재 최대 x좌표, 최소 x좌표, 최대 y좌표, 최소 y좌표 찾기

void dfs(int x, int y) {
    visited[x][y] = 1;
    if (x > max_x) max_x = x;
    if (x < min_x) min_x = x;
    if (y > max_y) max_y = y;
    if (y < min_y) min_y = y;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny] != 1) continue;

        dfs(nx, ny);
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

    int max_cnt = -2134567890;
    int fence;
    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                //cout << max_x << " " << min_x << " " << max_y << " " << min_y << "\n";
                fence = (max_x - min_x + 1) * 2 + (max_y - min_y + 1) * 2 + 4;
                result.push_back(fence);
                if (fence > max_cnt) max_cnt = fence;
           
                max_x = MY_MAX;
                min_x = MY_MIN;
                max_y = MY_MAX;
                min_y = MY_MIN;
            }
        }
    }
    
    cout << *max_element(result.begin(),result.end());
    
    
}