#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
struct Node {
	int y, x;
};
int n, q;
queue<Node>qq;
int arr[70][70];
int arrfake[70][70];
int visited[70][70];
int num;
int final = 0;
int flag = 0;
int maxval = 0;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };

void minused(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= num || nx >= num) {
			cnt++;
			continue;
		}
		if (arr[ny][nx] == 0)cnt++;
	}
	if (cnt > 1)qq.push({ y, x });
}

void rotate(int change) {
	int k = 0;
	int kk = 0;
	int kkk = 0;
	while (k < num) {
		while (kk < num) {
			for (int i = k; i < k + change; i++) {
				int jj = k + change - 1;
				for (int j = kk; j < kk + change; j++) {
					arrfake[i][j] = arr[jj][i + kkk];
					jj--;
				}
			}
			kk += change;
			kkk += change;
		}
		k += change;
		kk = 0;
		kkk = 0 - k;
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr[i][j] = arrfake[i][j];
		}
	}
}

void bfs(int y, int x) {
	final = 0;
	queue<Node>qqq;
	qqq.push({ y, x });
	while (!qqq.empty()) {
		Node now = qqq.front();
		qqq.pop();
		if (visited[now.y][now.x] == 1)continue;
		visited[now.y][now.x] = 1;
		final++;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= num || nx >= num)continue;
			if (arr[ny][nx] == 0)continue;
			qqq.push({ ny, nx });
		}
	}
	if (final > maxval)maxval = final;
	if (maxval >= num * num / 2)flag = 1;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie();
	cout.tie();
	
	cin >> n >> q;
	num = pow(2, n);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int l;
		cin >> l;
		int change = pow(2, l);
		if(change != 1) rotate(change);

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (arr[i][j] == 0)continue;
				minused(i, j);
			}
		}
		
		while (!qq.empty()) {
			Node now = qq.front();
			arr[now.y][now.x]--;
			qq.pop();
		}
	}
	int sum = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j] != 0 && flag==0) {
				bfs(i, j);
				memset(visited, 0, sizeof(visited));
			}
			sum += arr[i][j];
		}
	}
	cout << sum << "\n" << maxval;
}
