#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

struct coord {
	int x;
	int y;
};

int n, m;
char board[51][51];
int visited[51][51];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<coord> q;

int temp_result = -2134567890;

int bfs(coord start) {
	visited[start.x][start.y] = 1;
	q.push(start);

	while (!q.empty()) {
		coord now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == 'W') continue;

			visited[nx][ny] = visited[now.x][now.y] + 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp_result = max(visited[i][j], temp_result);
		}
	}
	return temp_result - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int result = -2134567890;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			temp_result = -2134567890;

			if (board[i][j] == 'W') continue;
			result = max(bfs({ i,j }),result);
		}
	}
	cout << result;
}