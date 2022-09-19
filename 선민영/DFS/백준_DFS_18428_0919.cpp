#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
char arr[10][10];
int n;
int cnt;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int flag;
int final;
int teacher = 0;

void check(int y, int x) {
	for (int j = 0; j < 4; j++) {
		for (int i = 1; i <= n; i++) {
			int ny = y + ydir[j] * i;
			int nx = x + xdir[j] * i;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)break;
			if (arr[ny][nx] == 'O'||arr[ny][nx]=='T')break;
			if (arr[ny][nx] == 'S') {
				return;
			}
		}
	}
	final++;
	return;
}

void checkit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'T') {
				check(i, j);
			}
		}
	}
}

void dfs(int y, int x) {
	if (cnt == 3) {
		final = 0;
		checkit();
		if (final == teacher)flag = 0;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 'X')continue;
			arr[i][j] = 'O';
			cnt++;
			dfs(i, j);
			cnt--;
			arr[i][j] = 'X';
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T')teacher++;
		}
	}
	cnt = 0;
	flag = 1;
	dfs(0,0);
	if (flag==0)cout << "YES";
	else cout << "NO";
}