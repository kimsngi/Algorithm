#include <iostream>
#include <queue>
using namespace std;
int map[1000][1000];
struct coor {
	int y;
	int x;
};
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int n, m;
int visited[1000][1000];
queue<coor> q;
int maxcnt;
int flag;
void bfs() {
	

	while (!q.empty()) {

		coor now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (visited[ny][nx] > 0)continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			maxcnt = max(maxcnt, visited[ny][nx]);
			q.push({ ny,nx });
			
		}

	}

}

int main() {
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {

				q.push({ i,j });
				visited[i][j] = 1;
			}
			else if (map[i][j] == -1) {
				visited[i][j] = 1;
			}

		}
	}
	maxcnt = 1;
	bfs();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				flag = 1;
			}
		}
	}

	if (flag) {
		cout << -1;

	}
	else {
		cout << maxcnt - 1;
	}

}