#include <iostream>
#include <vector>

using namespace std;

int height, width; //맵 크기 변수
int map[100][100]; //싱크홀 맵
int visited[100][100]; //방문 기록

struct Edge {
	int y; //y축 좌표
	int x; //x축 좌표
};
vector <Edge> sinkhole[100]; //싱크홀 기록 벡터

int index = 0; //벡터[0]부터 순서대로 기록
void func(int y, int x) {
	int di[2][4] = { //방향 벡터
		{-1,0,1,0},
		{0,1,0,-1}
	};

	sinkhole[index].push_back({ y,x }); //벡터에 현재 좌표(싱크홀 좌표) 푸시

	for (int i = 0; i < sinkhole[index].size(); i++) { //현재 index의 사이즈만큼 사이클이 돌아감(진입시 사이즈==1)
		for (int j = 0; j < 4; j++) {
			int ny = sinkhole[index][i].y + di[0][j]; //방향 벡터 입력
			int nx = sinkhole[index][i].x + di[1][j];
			if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;

			if (map[ny][nx] == 0) continue;
			sinkhole[index].push_back({ ny,nx }); //싱크홀 좌표일 시 현재 인덱스에 푸시(현재 인덱스 사이즈도 +1)
		}
	}

	index++; //한 사이클이 끝나면 인덱스 증가시킴
}

int func(vector <Edge> sinkhole) {
	int maxy = 0, maxx = 0, miny = 100, minx = 100;

	for (int i = 0; i < sinkhole.size(); i++) {
		if (maxy < sinkhole[i].y) maxy = sinkhole[i].y;
		if (maxx < sinkhole[i].x) maxx = sinkhole[i].x;
		if (miny > sinkhole[i].y) miny = sinkhole[i].y;
		if (minx > sinkhole[i].x) minx = sinkhole[i].x;
	}

	return (maxy - miny + 2) * 2 + (maxx - minx + 2) * 2;
}

int main() {

	//맵 정보 입력
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	//싱크홀 찾기
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (visited[i][j] == 1) continue;
			visited[i][j] = 1; //방문 기록

			if (map[i][j] == 0) continue;
			func(i, j);
		}
	}

	int maxfences = 0;
	for (int i = 0; i < index; i++) {
		int nowfences = func(sinkhole[i]);

		if (maxfences < nowfences) maxfences = nowfences;
	}

	cout << maxfences;
}