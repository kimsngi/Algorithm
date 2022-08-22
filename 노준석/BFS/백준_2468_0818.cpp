#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define MAX_DIST 2134567890
#pragma warning(disable:4996)

struct coord {
	int x;
	int y;
};

int N;
int board[101][101];
int visited[101][101];
int max_water = -2134567890;
int min_water = 0;
int max_result = -2134567890;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void initFunc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
queue<coord> q;

// 안전 영역의 범위를 체크하는 bfs
void bfs(int water) {
	

	while (!q.empty()) {
		coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			// 범위 체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			// 방문 체크
			if (visited[nx][ny]) continue;
			// 물의 높이보다 낮은지 체크
			if (board[nx][ny] <= water) continue;
			
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > max_water) max_water = board[i][j];
		}
	}

	// 내리는 비의 양에 따른 모든 경우 조사
	for (int water = min_water; water <= max_water; water++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 물 높이보다 낮으면 잠기게 된다
				if (board[i][j] <= water) continue;
				if (visited[i][j]) continue;

				// bfs 탐색, 안전영역 개수 증가
				
				q.push({ i,j });
				visited[i][j] = 1;
				bfs(water);
				cnt++;
			}
		}
		if (cnt > max_result) max_result = cnt;
		
		
		initFunc();
	}
	cout << max_result;
}