#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int arr[1001][1001];
int dist[1001][1001]={0,};
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
struct Node {
	int y, x;
};
queue<Node>q;
int n, m;
int maxval = 0;
void bfs() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == -1 || arr[ny][nx]==1) continue;
			dist[ny][nx] = dist[now.y][now.x] + 1;
			if (dist[ny][nx] > maxval)maxval = dist[ny][nx];
			arr[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}
int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	int flag = 0;
	if (q.size() == n * m)cout << 0;
	else {
		bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					cout << -1;
					flag = 1;
					break;
				}
			}if (flag == 1)break;
		}
		if (flag == 0)cout << maxval;
	}
	
}