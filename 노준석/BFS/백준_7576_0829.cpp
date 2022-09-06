#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct coord {
	int x;
	int y;
};

int n, m;
int board[1001][1001];
int visited[1001][1001];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<coord> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		coord now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == -1) continue;

			board[nx][ny] = board[now.x][now.y] + 1;
			visited[nx][ny] = visited[now.x][now.y] + 1;
			q.push({ nx,ny });
		}
	}
	bool flag = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && board[i][j]!=-1) {
				flag = false;
				cout << -1;
				return 0;
			}
		}
	}

	int result = -2134567890;
	if (flag) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				result = max(visited[i][j], result);
			}
		}
	}
	cout << result - 1;

	
}