#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
int arr[101][101];
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,1,-1 };
int ybig;
int ysmall;
int xbig;
int xsmall;
int visited[101][101] = { 0, };

void dfs(int y, int x) //싱크홀 찾기
{
	arr[y][x] = 0;
	if (y > ybig) ybig = y;
	if (y < ysmall) ysmall = y;
	if (x > xbig)xbig = x;
	if (x < xsmall)xsmall = x;
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (arr[ny][nx] == 0) continue;
		if (visited[ny][nx] == 1)continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main() {
	cin >> n >> m;
	int brr[100] = { 0, };
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[i][k];
		}
	} // 맵 입력받기
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (arr[i][k] == 1) {
				ybig = 0;
				ysmall = 2134567890;
				xbig = 0;
				xsmall = 2134567890;
				dfs(i, k); // 싱크홀 하나 찾으면 이어져 있는 전체 싱크홀 찾기
				brr[cnt] = (ybig - ysmall + 3) * (xbig - xsmall + 3) - (ybig - ysmall + 1) * (xbig - xsmall + 1);
				// 싱크홀을 두른 네모에서 싱크홀 크기 빼면 울타리 조각 수
				cnt++;
			}
		}
	}
	int maximal = 0;
	for (int i = 0; i < cnt; i++) {
		if (brr[i] > maximal) maximal = brr[i];
	} // 가장 많은 울타리 조각 찾기
	cout << maximal;
}