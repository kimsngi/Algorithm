#include <iostream>
#include <queue>
using namespace std;
struct coor {
	int y;
	int x;

};
int n;
int arr[101][101];
int visited[101][101];
int cnt;
queue<coor> q;
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};

void bfs(coor start) {
	
	q.push(start);
	while (!q.empty()) {

		coor now = q.front();
		q.pop();
		visited[now.y][now.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (visited[ny][nx] == 1)continue;


			visited[ny][nx] = 1;
			q.push({ ny,nx });

		}

	}
	cnt++;
}


void searchstart(int wheight) {
	int sy, sx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= wheight) {
				visited[i][j] = 1;
			}
			
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 1) {
				sy = i;
				sx = j;
				bfs({ sy,sx });
			}
		}
	}

}


int main() {
	int maxval = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > maxval) maxval = arr[i][j];
		}
	}

	int maxcnt = 0;
	// 물의 높이는 0부터
	for (int i = 0; i <= maxval; i++) {

		cnt = 0;

		searchstart(i);

		if (cnt > maxcnt) maxcnt = cnt;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}
	}

	cout << maxcnt;

}