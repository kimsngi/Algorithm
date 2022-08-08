#include <iostream>
#include <queue>
using namespace std;
int arr[1000][1000];
struct coor {
	int y;
	int x;
	int num;
};

bool operator<(coor a, coor b) {

	if (a.num < b.num) return false;
	if (a.num > b.num) return true;

	return false;


}



priority_queue<coor> bomb;

int dat[1000][1000];
int dc[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			bomb.push({ i,j,arr[i][j] });

		}
	}

	int time = 0;
	while (!bomb.empty()) {

		coor now = bomb.top();
		bomb.pop();
		if (dat[now.y][now.x] == 1)continue;

		dat[now.y][now.x] = 1;
		time = now.num;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dc[0][i];
			int nx = now.x + dc[1][i];


			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;

			dat[ny][nx] = 1;


		}

	}


	cout << time << "ÃÊ";


}

