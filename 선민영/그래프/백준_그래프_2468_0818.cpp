#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
int visited[101][101] = { 0, };
int ydir[4] = { 0,0,1,-1 };
int xdir[4] = { 1, -1, 0,0 };
int n;
void ff(int i, int k) {

	visited[i][k] = 0;
	for (int p = 0; p < 4; p++) {
		int ny = i + ydir[p];
		int nx = k + xdir[p];
		if (ny<0 || nx<0 || ny>=n || nx>=n)continue;
		if (visited[ny][nx] == 0)continue;
		visited[ny][nx] = 0;
		ff(ny, nx);

	}
}
int main() {
	int maxval = 1;
	int min = 10;
	int max = 0;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> arr[i][k];
			if (arr[i][k] > max) max = arr[i][k];
			if (arr[i][k] < min) min = arr[i][k];
		}
	}
	for (int p = min+1; p <= max; p++) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				if (arr[i][k] >= p) visited[i][k] = 1;
			}
		} 
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				if (visited[i][k] == 1) {
					ff(i, k);
					cnt++;
				}
			}
		}
		if (cnt > maxval) maxval = cnt;
		cnt = 0;
	}
	cout << maxval;
}
