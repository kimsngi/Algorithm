#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct coord {
	int x;
	int y;
};

int N, Q;
int arrSize = 0;
int board[64][64];
int visited[64][64];
int temp_arr[64][64];
queue<int> L;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 배열 회전시키기
void rotateArr(int startX,int startY, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp_arr[j + startX][size - i - 1 + startY] = board[i + startX][j + startY];
		}
	}
}

void fireStrom(int l) {

	for (int i = 0; i < arrSize; i += l) {
		for (int j = 0; j < arrSize; j += l) {
			rotateArr(i, j, l);
		}
	}

	// 배열 회전시킨거 저장
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			board[i][j] = temp_arr[i][j];
		}
	}

	queue<coord> q;
	for (int x = 0; x < arrSize; x++) {
		for (int y = 0; y < arrSize; y++) {

			int temp_cnt = 0; // 주변에 얼음이 있는 칸 개수
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= arrSize || ny < 0 || ny >= arrSize) continue;

				if (board[nx][ny] > 0) temp_cnt++;
			}
			if (temp_cnt < 3) q.push({ x,y });
		}
	}
	// 녹을 곳 얼음 녹이기
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		board[now.x][now.y] -= 1;
	}
}

int max_size = -2134567890;
int dfs_cnt = 0;

void dfs(coord now) {
	visited[now.x][now.y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = now.x + dx[i];
		int ny = now.y + dy[i];

		if (nx < 0 || nx >= arrSize || ny < 0 || ny >= arrSize) continue;
		if (visited[nx][ny]) continue;
		if (board[nx][ny] <= 0) continue;

		visited[nx][ny] = 1;
		dfs_cnt++;
		dfs({ nx,ny });
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N - 격자 크기 결정
	// Q - 파이어스톰 시전 횟수
	cin >> N >> Q;
	arrSize = pow(2, N);
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int num;
		cin >> num;
		L.push(num);
	}

	while (!L.empty()) {
		memset(temp_arr, 0, sizeof(temp_arr));
		int cur = L.front(); L.pop();
		fireStrom(pow(2, cur)); // 얼음 녹이기
	}

	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			if (board[i][j] > 0) dfs({ i,j });
			max_size = max(max_size, dfs_cnt);

			dfs_cnt = 0;
			memset(visited, 0, sizeof(visited));
		}
	}

	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			if(board[i][j]>0)
				sum += board[i][j];
		}
	}
	if (max_size == 0) cout << sum << "\n" << 0;
	else cout << sum << "\n" << max_size + 1;
	return 0;
}