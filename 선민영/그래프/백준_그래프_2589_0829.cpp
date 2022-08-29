#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
char arr[51][51];
int visited[51][51] = { 0, };
int dist[51][51] = { 0, };
int n, m;
int mini = 0;

struct Node {
	int y, x;
};

int final;
void bfs(int y, int x) {
	queue<Node>q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == 'W')continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			dist[ny][nx] = dist[now.y][now.x] + 1;
			if (dist[ny][nx] > mini)mini = dist[ny][nx];
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
				memset(visited, 0, sizeof(visited));
				memset(dist, 0, sizeof(dist));
			}
		}
	}
	cout << mini;
}