//2022년 08월 04일 알고리즘 스터디 문제2

#include <iostream>
#include <queue>

using namespace std;

struct bomb {
	int y; //폭탄 y좌표
	int x; //폭탄 x좌표
	int num; //폭탄 번호
};

int operator < (bomb A, bomb B) { //pq 우선순위 정의
	return A.num > B.num; //num값이 작은순으로
}

int arr[1000][1000]; //폭탄 필드
int DAT[1000][1000]; //필드 중 안 터진 곳 0, 터진 곳 1
priority_queue <bomb> bom;
int di[2][5] = { //터지는 필드 방향 배열
	{0,-1,0,1,0},
	{0,0,1,0,-1}
};

int main() {
	int n;
	cin >> n; //필드 사이즈

	for (int i = 0; i < n; i++) { //필드와 pq에 폭탄 정보 입력
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			bom.push({ i,j,arr[i][j] });
		}
	}

	int sec = 0; //걸리는 시간
	while (!bom.empty()) {
		bomb t = bom.top(); bom.pop();
		if (DAT[t.y][t.x] == 1) continue;
		sec = t.num;
		for (int j = 0; j < 5; j++) {
			int ny = t.y + di[0][j];
			int nx = t.x + di[1][j];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			DAT[ny][nx] = 1;
		}
	}

	cout << sec << "초";
}