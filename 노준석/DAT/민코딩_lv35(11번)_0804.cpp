#include<iostream>
#include<queue>
#include <vector>
using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

priority_queue<Edge> pq;
string input;
int n;

int board[1001][1001];
int visited[1001][1001];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 저장된 숫자가 있는 위치 저장할 구조체
struct coord {
    int x;
    int y;
};

// dat 배열
coord location[1000001];
coord dat[1000001];


queue<coord> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            // 특정 번호가 저장되어 있는 x,y좌표 저장
            location[board[i][j]] = { i,j };
        }
    }

    int time = 1;
    // {0,2} 전달
    q.push(location[1]);
    // 1번 탐색 완료
    visited[location[1].x][location[1].y] = 1;
    int temp_num;
    while (!q.empty()) {
        temp_num = 0;
        coord now = q.front();
        q.pop();
        // 현재 좌표도 제거 처리
        temp_num = board[now.x][now.y];
        board[now.x][now.y] = -100;
        int end_flag = true;

        // 4방향 돌면서 폭탄 제거
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            // 폭탄 터진 곳은 -100 처리
            board[nx][ny] = -100;
        }
        time += 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != -100) {
                    // 만약 하나라도 제거해야할 폭탄이 남아있다면
                    // 끝내면 안된다
                    end_flag = false;
                    break;
                }
            }
        }
        if (end_flag) {
            
            break;
        }

        // 다음 폭탄 터질 곳을 큐에 넣는다
        for (int i = time; i <= n * n; i++) {
            int next_x = location[i].x;
            int next_y = location[i].y;
            if (board[next_x][next_y] != -100) {
                visited[next_x][next_y] = 1;
                q.push({ next_x ,next_y });
                break;
            }
        }

    }

    cout << temp_num << "초";


}