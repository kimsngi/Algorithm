#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>

using namespace std;
struct coord {
	int x;
	int y;
};

int board[9][9];
int visited[9][9];

vector<coord> v; // 0으로 적힌 것들(채워야 할 것들) 넣어주는 큐

// 행 체크
bool checkRow(int x,int num) {
	for (int i = 0; i < 9; i++) {
		// 같은 행에 있는지 체크
		if (board[x][i] == num) return false;
	}
	return true;
}

// 열 체크
bool checkColumn(int y,int num) {
	for (int i = 0; i < 9; i++) {
		// 같은 열에 있는지 체크
		if (board[i][y] == num) return false;
	}
	return true;
}

// 3x3 사각형 체크
bool checkSquare(int x,int y,int num) {
	int tempX = x / 3;
	int tempY = y / 3;

	for (int i = tempX * 3; i < tempX * 3 + 3; i++) {
		for (int j = tempY * 3; j < tempY * 3 + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}
	return true;
}

void dfs(int depth) {
	// 기저 조건 -> 모든 0으로 된 노드를 돌았으면 -> 스도쿠를 다 채웠다
	if (depth == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}

	// 재귀 호출
	int nx = v[depth].x;
	int ny = v[depth].y;

	// 1부터 9까지 숫자 하나씩 넣어가며 체크
	for (int i = 1; i <= 9; i++) {
		if (checkRow(nx, i) && checkColumn(ny, i) && checkSquare(nx, ny, i)) {
			board[nx][ny] = i;
			dfs(depth + 1);

			board[nx][ny] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 0) continue;
		}
	}
	dfs(0);
}