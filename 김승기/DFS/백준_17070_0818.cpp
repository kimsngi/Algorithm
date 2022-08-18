#include <iostream>
using namespace std;
int arr[17][17];
struct coor {
	int y;
	int x;
};
int n;
int dr1[3][2] = {
	{0,1},
	{1,1},
	{1,3}
};
int dr2[3][2] = {
	{1,1},
	{0,1},
	{2,3}
};
int dr3[3][3] = {
	{0,1,1},
	{1,0,1},
	{1,2,3}
};
int cnt;

void dfs(coor now,int type) {

	if (now.y ==n && now.x ==n) {
		cnt++;
		return;
	}

	//가로
	if(type==1){
	
		for (int i = 0; i < 2; i++) {
		

			int ny = now.y + dr1[0][i];
			int nx = now.x + dr1[1][i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
			if (arr[ny][nx] >0)continue;
			if (i == 1) {
				if (arr[ny - 1][nx] >0 || arr[ny][nx - 1] >0)continue;
			}

			arr[ny][nx]++;
			dfs({ ny,nx },dr1[2][i]);
			arr[ny][nx]--;
		}
	}
	//세로
	if (type == 2) {
		for (int i = 0; i < 2; i++) {


			int ny = now.y + dr2[0][i];
			int nx = now.x + dr2[1][i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
			if (arr[ny][nx]>0)continue;
			if (i == 1) {
				if (arr[ny - 1][nx] >0 || arr[ny][nx - 1] > 0 )continue;
			}
			arr[ny][nx]++;
			dfs({ ny,nx }, dr2[2][i]);
			arr[ny][nx]--;
		}

	}
	//대각선
	if (type == 3) {
		for (int i = 0; i < 3; i++) {


			int ny = now.y + dr3[0][i];
			int nx = now.x + dr3[1][i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
			if (arr[ny][nx] > 0)continue;
			if (i == 2) {
				if (arr[ny - 1][nx] > 0 || arr[ny][nx - 1] > 0)continue;
			}
			arr[ny][nx]++;
			dfs({ ny,nx }, dr3[2][i]);
			arr[ny][nx]--;
		}

	}

}





int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	arr[1][1] = 1;
	arr[1][2] = 1;
	dfs({1,2},1);

	cout << cnt;
}