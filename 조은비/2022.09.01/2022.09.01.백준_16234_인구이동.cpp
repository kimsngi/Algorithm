//맞았습니다!! / 2068KB / 52ms
#include <iostream>

using namespace std;

int N; //땅 크기
int L; //인구 차이 최소
int R; //인구 차이 최대
int map[50][50]; //[N][N] = 인구 수
int flag;

struct node { int y; int x; int pp; int cnt; };

bool operator < (node A, node B) {
	if (A.y == B.y) return A.x < B.x;
	
	return A.y < B.y;
}

node uni[50][50];

node uniFind(int y, int x) {
	node unit = uni[y][x];
	if (unit.y == y && unit.x == x) return unit;
	return uni[y][x] = uniFind(unit.y, unit.x);
}

void uniMerge(int y1, int x1, int y2, int x2) {
	node unit1 = uniFind(y1, x1);
	node unit2 = uniFind(y2, x2);

	if (unit1.y == unit2.y && unit1.x == unit2.x) return;

	if (unit1 < unit2) {
		uni[unit2.y][unit2.x] = { unit1.y,unit1.x,0 };
		uni[unit1.y][unit1.x].pp += unit2.pp;
		uni[unit1.y][unit1.x].cnt += unit2.cnt;
	}
	else {
		uni[unit1.y][unit1.x] = { unit2.y,unit2.x,0 };
		uni[unit2.y][unit2.x].pp += unit1.pp;
		uni[unit2.y][unit2.x].cnt += unit1.cnt;
	}
}

void func() {
	flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			uni[i][j] = { i,j,map[i][j],1 };
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			int cha = abs(map[i][j] - map[i][j + 1]);
			if (cha >= L && cha <= R) {
				flag = 1;
				uniMerge(i, j, i, j + 1);
			}
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			int cha = abs(map[i][j] - map[i + 1][j]);
			if (cha >= L && cha <= R) {
				flag = 1;
				uniMerge(i, j, i + 1, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			node temp = uniFind(i, j);
			map[i][j] = temp.pp / temp.cnt;
		}
	}
	
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	flag = 1;

	int cnt = 0;
	while (flag) {
		func();
		cnt++;
	}

	cout << cnt - 1;
}