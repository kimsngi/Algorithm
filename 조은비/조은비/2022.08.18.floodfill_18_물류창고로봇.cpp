#include <iostream>
#include <queue>

using namespace std;

struct robot {
	int y;  //y좌표
	int x;  //x좌표
	int di; //방향 (0 ~ 3)
	int cmd; //커맨드 입력 횟수
};

int direction[4][2] = { //방향배열
	{-1, 0}, //북
	{ 0, 1}, //동
	{ 1, 0}, //남
	{ 0,-1}  //서
};

int N; //물류창고 세로 길이
int M; //물류창고 가로 길이
int map[101][101]; //장애물 and visited 입력
int visited[101][101][4]; //[y][x][di]
int y, x, di; //목표 좌표, 방향
queue <robot> q;

void commend(robot r) {

	//전진
	int ny, nx;

	for (int i = 1; i <= 3; i++) {
		ny = r.y + direction[r.di][0] * i;
		nx = r.x + direction[r.di][1] * i;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break; //범위를 벗어나면 전진불가
		if (map[ny][nx] == 1) break; //장애물 만나면 전진 불가
		if (visited[ny][nx][r.di] == 1) continue; //방문 장소 진입 불가
		visited[ny][nx][r.di] = 1;
		q.push({ ny,nx,r.di,r.cmd + 1 });
	}


	int ndi;

	//우회전
	if (r.di == 3) ndi = 0;
	else ndi = r.di + 1;
	if (visited[r.y][r.x][ndi] != 1) { //방문 장소 진입불가
		visited[r.y][r.x][ndi] = 1;
		q.push({ r.y, r.x, ndi, r.cmd + 1 });
	}

	//좌회전
	if (r.di == 0) ndi = 3;
	else ndi = r.di - 1;
	if (visited[r.y][r.x][ndi] != 1) {
		visited[r.y][r.x][ndi] = 1;
		q.push({ r.y, r.x, ndi, r.cmd + 1 });
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//시작좌표 입력
	int changeDi[5] = { 0,1,3,2,0 };

	cin >> y >> x >> di;
	y -= 1; x -= 1;
	di = changeDi[di];
	q.push({ y,x,di,0 });

	//도착좌표 입력
	cin >> y >> x >> di;
	y -= 1; x -= 1;
	di = changeDi[di];

	while (1) {
		robot r = q.front(); q.pop();
		if (r.y == y && r.x == x && r.di == di) {
			cout << r.cmd;
			break;
		}

		commend(r);
	}
}