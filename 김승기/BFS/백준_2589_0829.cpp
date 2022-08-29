#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

struct coor {
	int y;
	int x;
};

string map[50];
int h, w;
int cnt;
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int visited[50][50];
int maxcnt;

void bfs(coor st) {
	queue<coor> q;
	q.push(st);


	while (!q.empty()) {
		coor now = q.front();
		q.pop();	

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
			if (visited[ny][nx] >0)continue;
			if (map[ny][nx] == 'W')continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			maxcnt = max(visited[ny][nx] - 1, maxcnt);
			q.push({ ny,nx });

		}
	}

	
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}



	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			if (map[i][j] == 'L') {

				visited[i][j] = 1;
				bfs({i,j});
			}

			memset(visited, 0, sizeof(visited));
		}
	}

	cout << maxcnt;
}