#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct coord {
    int x;
    int y;
};

int h, w;
int board[11][11];
int visited[11][11];
vector<coord> path;
int max_score = -2134567890;

int temp_sum = 0;

int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

void dfs(int level,int x,int y){
    // 기저 조건
    if (level == h - 1) {
        /*for (int i = 0; i < path.size(); i++) {
            cout << path[i].x << " " << path[i].y << "\n";
        }
        cout << "--------------\n";*/
        if (temp_sum > max_score) max_score = temp_sum;
        return;
    }

    // 재귀
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (board[nx][ny] == 0) continue;
        if (visited[nx][ny]) continue;

        
        temp_sum += board[nx][ny];
        //path.push_back({ nx,ny });
        dfs(level + 1, nx, ny);
        temp_sum -= board[nx][ny];
        //path.pop_back();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    temp_sum += board[0][0];
    //path.push_back({ 0,0 });
    dfs(0, 0, 0);
    cout << max_score;
}