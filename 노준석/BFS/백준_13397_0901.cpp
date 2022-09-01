#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct coord {
    int x;
    int y;
};

int n;
int l, r;
int board[51][51];
int visited[51][51];


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<coord> q; // bfs탐색용 queue
vector<coord> v; // 연합국가 vector

vector<coord> bfs(coord start) {
    vector<coord> temp;
    visited[start.x][start.y] = 1;
    temp.push_back(start); // 현재 국가를 연합국에 추가
    q.push(start);

    while (!q.empty()) {
        coord now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (visited[nx][ny]) continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            int diff = abs(board[now.x][now.y] - board[nx][ny]);
            if (diff<l || diff>r) continue;

            visited[nx][ny] = 1;
            temp.push_back({ nx,ny }); // 탐색 node를 연합국에 추가
            q.push({ nx,ny });
        }
    }
    return temp;
}

void move(vector<coord> cur) {
    int sum = 0;
    for (int i = 0; i < cur.size(); i++) {
        int x = cur[i].x;
        int y = cur[i].y;

        sum += board[x][y];
    }
    int temp_div = sum / cur.size();

    for (int i = 0; i < cur.size(); i++) {
        int x = cur[i].x;
        int y = cur[i].y;

        board[x][y] = temp_div;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    int cnt = 0;

    while (1) {
        bool move_flag = false;
        memset(visited, 0, sizeof(visited));

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y]) continue; // 이미 방문했다면(연합에 속해졌다면) 가지치기

                // 현재 국가로부터 연합을 모두 구하기
                vector<coord> cur_union = bfs({ x,y });
                if (cur_union.size() > 1) {
                    move_flag = true;
                    move(cur_union);
                }
                else {
                    continue;
                }
            }
        }

        // 인구 이동 할 국가가 없으면 반복문 탈출
        if (!move_flag) break;
        else cnt++;
    }

    cout << cnt;

}