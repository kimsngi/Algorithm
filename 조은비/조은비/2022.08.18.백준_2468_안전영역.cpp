#include <iostream>
#include <queue>

using namespace std;

int N; //맵 크기
int map[100][100]; //맵 정보 | [y][x] = 높이
int visited[100][100]; // 방문 정보 0/1
int cntMax; //안전 영역 개수

struct edge { int y; int x; };

queue <edge> q;

int di[4][2] = { //방향 배열 (4방향) | [방향][0=y, 1=x]
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0,-1}
};

void reset() { //visited 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

void safe(int y, int x, int height) { //같은 안전 지대 영역의 visited를 1로 기록

	q.push({ y,x });

	while (!q.empty()) {

		edge temp = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = temp.y + di[i][0];
			int nx = temp.x + di[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			if (visited[ny][nx] == 1) continue;

			if (map[ny][nx] > height) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			} 

		}
	}
}

int isSafe(int x) { // 높이 x 이하의 지역이 물에 잠길 때 안전 영역 개수

	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (visited[i][j] == 1) continue;
			visited[i][j] = 1;

			if (map[i][j] <= x) continue;
			cnt++;

			safe(i, j, x);

		}
	}

	return cnt;
}


int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {

		reset();

		int cnt = isSafe(i);

		cntMax = max(cntMax, cnt);
	}

	cout << cntMax;
}