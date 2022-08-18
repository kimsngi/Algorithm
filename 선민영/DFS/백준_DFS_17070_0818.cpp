#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int arr[17][17];
int ydir[3] = { 0, 1, 1 }; 
int xdir[3] = { 1, 1, 0 };
int n;
long long cnt = 0;
void pipe(int y, int x, int version) {

	if (y == n-1 && x == n-1) {
		cnt++;
		return;
	}
	if (version == 1) {
		for (int i = 0; i < 2; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];
			if (ny < 0 || nx<0 || ny>=n || nx>=n)continue;
			if (arr[ny][nx] == 1)continue;
			if (i == 1) {
				if (arr[ny - 1][nx] == 1 || arr[ny][nx - 1] == 1)continue;
				pipe(ny, nx, i + 1);
			}
			else pipe(ny, nx, i + 1);

		}
	}
	else if(version == 2) {
		for (int i = 0; i < 3; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (arr[ny][nx] == 1)continue;
			if (i == 1) {
				if (arr[ny - 1][nx] == 1 || arr[ny][nx - 1] == 1)continue;
				pipe(ny, nx, i + 1);
			}
			else pipe(ny, nx, i + 1);

		}
	}
	else if (version == 3) {
		for (int i = 1; i < 3; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (arr[ny][nx] == 1)continue;
			if (i == 1) {
				if (arr[ny - 1][nx] == 1 || arr[ny][nx - 1] == 1)continue;
				pipe(ny, nx, i + 1);
			}
			else pipe(ny, nx, i + 1);

		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			cin >> arr[i][l];
		}
	}
	pipe(0, 1, 1);
	cout << cnt;
}