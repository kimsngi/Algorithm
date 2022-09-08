#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int y, x;
};
int arr[51][51];
int visited[51][51];
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1, -1, 0, 0 };
int n, l, r;
int sum;
int cnt;
int flag = 1;
void bfs(int y, int x) {
	queue<Node>q;
	queue<Node>qq;
	q.push({ y, x });
	qq.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			int k = arr[ny][nx] - arr[now.y][now.x];
			if (k < 0)k *= -1;
			if (k<l || k>r)continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			sum += arr[ny][nx];
			cnt++;
			q.push({ ny, nx });
			qq.push({ ny, nx });
		}
	}
	while (!qq.empty()) {
		arr[qq.front().y][qq.front().x] = sum / cnt;
		qq.pop();
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int final = 0;
	while (1) {
		flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					flag++;
					sum = arr[i][j];
					cnt = 1;
					bfs(i, j);
				}
			}
		}
		if (flag == n*n)break;
		final++;
		memset(visited, 0, sizeof(visited));
	}cout << final;
}