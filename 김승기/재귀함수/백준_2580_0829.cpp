#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
struct coor {
	int y;
	int x;
};
int map[9][9];
int area[9][9] = {
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9}
};
coor start[10] = {
	{0,0},
	{0,0},
	{0,3},
	{0,6},
	{3,0},
	{3,3},
	{3,6},
	{6,0},
	{6,3},
	{6,6},
};

vector<coor> v;

int dat[10];
int dr[2][9] = {
	{0,0,0,1,1,1,2,2,2},
	{0,1,2,2,1,0,0,1,2}
};
int cnt;
int flag;

bool rowcheck(int row,int now) {

	memset(dat, 0, sizeof(dat));

	for (int i = 0; i < 9; i++) {
		dat[map[row][i]]++;
		
	}
	if (dat[now] >0) {
		return true;
	}
	else {
		return false;
	}

}

bool colcheck(int col, int now) {

	memset(dat, 0, sizeof(dat));

	for (int i = 0; i < 9; i++) {
		dat[map[i][col]]++;

	}
	if (dat[now] >0) {
		return true;
	}
	else {
		return false;
	}

}

bool areacheck(coor st,int now) {

	memset(dat, 0, sizeof(dat));

	coor areast = start[area[st.y][st.x]];

	for (int i = 0; i < 9; i++) {

		int ny = areast.y + dr[0][i];
		int nx = areast.x + dr[1][i];

		dat[map[ny][nx]]++;
	}
	if (dat[now] >0) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int level) {
	if (flag)return;

	if (level == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		flag = 1;
		return;
	}

	coor st = v[level];


	for (int i = 1; i <= 9; i++) {
		
		int now = i;

		if(rowcheck(st.y, now)) continue;
		if(colcheck(st.x, now)) continue;
		if(areacheck(st, now)) continue;


		map[st.y][st.x] = now;

		dfs(level+1);
		map[st.y][st.x] = 0;

	}

	return;
	
}

int main(){

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				cnt++;
				v.push_back({ i,j });
			}
		}
	}

	dfs(0);

}