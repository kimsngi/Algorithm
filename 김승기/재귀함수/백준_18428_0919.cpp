#include <iostream>
#include <vector>
using namespace std;
struct coor {
	int y;
	int x;
};
char map[6][6];
int block[6][6];
int n;
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int cnt;

vector<coor> teacher;
vector<coor> preblock;
void dfs(coor st,coor now,int mode) {

	if (map[now.y][now.x] == 'S') {
		int by = st.y + dr[0][mode];
		int bx = st.x + dr[1][mode];

		if (map[by][bx] == 'S') {
			cout << "NO";
			exit(0);
		}

		for (int i = 0; i < preblock.size(); i++) {
			if (preblock[i].y == now.y && preblock[i].x == now.x)continue;

			block[preblock[i].y][preblock[i].x]++;
		}

		cnt++;
		return;
	}



	int ny = now.y + dr[0][mode];
	int nx = now.x + dr[1][mode];

	if (ny < 0 || nx < 0 || ny >= n || nx >= n)return;
	if (map[ny][nx] == 'T')return;
	
	preblock.push_back({ ny,nx });
	dfs(st,{ ny,nx },mode);

}



int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T') {
				teacher.push_back({ i,j });

			}
		}
	}

	for (int i = 0; i < teacher.size(); i++) {
		for (int mode = 0; mode < 4; mode++) {

			dfs(teacher[i],teacher[i], mode);
			preblock.clear();
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (block[i][j] == 2) {
				cnt = cnt - 2;
				ans++;
			}
		}
	}

	ans = ans + cnt;

	if (ans <= 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}