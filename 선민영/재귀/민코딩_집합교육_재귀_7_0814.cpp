#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int height, width;
int xdir[3] = { -1, 0, 1 };
int arr[11][11];
int dist[11][11];
int maxd = -2134567890;
struct Node{ 
	int y;
	int x;
};
void jump(Node now) {
	if (now.y == height - 1) {
		if (maxd < dist[now.y][now.x]) maxd = dist[now.y][now.x];
	}
	for (int i = 0; i < 3; i++) {
		int ny = now.y + 1;
		int nx = now.x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= height || nx >= width)continue;
		if (arr[ny][nx] == 0) continue;
		dist[ny][nx] = dist[now.y][now.x] + arr[ny][nx];
		jump({ ny, nx });
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
		}
	}
	dist[0][0] = arr[0][0];
	jump({ 0,0 });
	cout << maxd;
}