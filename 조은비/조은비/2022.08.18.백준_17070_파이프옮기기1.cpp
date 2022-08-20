#include <iostream>

using namespace std;

int N; //집의 크기 : N * N
int map[16][16]; //집 | 0:빈칸, 1:벽
int cnt; // 방법 수

void dfs(int y, int x, string dir) { //y좌표, x좌표, 방향
	if (y == N - 1 && x == N - 1) {
		cnt++;
		return;
	}

	if (dir == "horizon") { //파이프가 가로일 때
		if (x + 1 >= N) return;
		if (map[y][x + 1] == 0) { //가로로 진행
			dfs(y, x + 1, "horizon");
		}

		if (y + 1 >= N) return;
		if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //대각선으로 진행
			dfs(y + 1, x + 1, "diagonal");
		}
	}

	if (dir == "vertical") { //파이프가 세로일 때
		if (y + 1 >= N) return;
		if (map[y + 1][x] == 0) { //세로로 진행
			dfs(y + 1, x, "vertical");
		}

		if (x + 1 >= N) return;
		if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //대각선으로 진행
			dfs(y + 1, x + 1, "diagonal");
		}
	}

	if (dir == "diagonal") { //파이프가 대각선일 때
		if (x + 1 < N) {
			if (map[y][x + 1] == 0) { //가로로 진행
				dfs(y, x + 1, "horizon");
			}
		}

		if (y + 1 < N) {
			if (map[y + 1][x] == 0) { //세로로 진행
				dfs(y + 1, x, "vertical");
			}
		}

		if (x + 1 < N && y + 1 < N) {
			if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //대각선으로 진행
				dfs(y + 1, x + 1, "diagonal");
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 1, "horizon");

	cout << cnt;
}