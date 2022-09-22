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

int N;
char board[7][7];
char replace_board[7][7];
bool answer_flag = false;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<coord> teachers; // 선생 좌표 저장
bool temp_flag = false; // 학생 감시 성공 플래그

// 현재 위치에 세웠을 때 선생이 체크할 수 있는지
void checkFunc() {

	queue<coord> temp_queue = teachers;
	
	temp_flag = false;
	while (!temp_queue.empty()) {
		coord now = temp_queue.front(); temp_queue.pop();
		for (int i = 0; i < 4; i++) {
			int cnt = 1;
			while (1) {
				int nx = now.x + dx[i] * cnt;
				int ny = now.y + dy[i] * cnt;

				if (nx < 1 || nx >= N || ny < 1 || ny >= N) break;
				if (replace_board[nx][ny] == 'O') break;

				// 학생 찾은 경우 return
				if (board[nx][ny] == 'S') {
					temp_flag = true;
					return;
				}
				cnt += 1;
			}
		}
	}
	if (!temp_flag) answer_flag = true;
}

// 장애물 3개 세우기
void makeObject(int level) {
	if (level == 3) {
		checkFunc();
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (replace_board[i][j] == 'X') {
				replace_board[i][j] = 'O';
				makeObject(level + 1);
				replace_board[i][j] = 'X';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teachers.push({ i,j });
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (board[x][y] == 'X') {
				// replace_board : 장애물 세우는 대체 map
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						replace_board[i][j] = board[i][j];
					}
				}

				replace_board[x][y] = 'O'; // 장애물 1개 세움
				makeObject(1); // 2개의 장애물을 더 설치하는 dfs
				replace_board[x][y] = 'X'; // 장애물 제거
			}
		}
	}

	if (answer_flag) cout << "YES";
	else cout << "NO";

	return 0;
}