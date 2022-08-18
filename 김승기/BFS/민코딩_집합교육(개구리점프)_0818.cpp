#include <iostream>
#include <queue>
using namespace std;
struct coor {
	int y;
	int x;
	int sum;
};

queue<coor> q;
int height, width;
int arr[11][11];
int dr[2][3] = {
	{1,1,1},
	{-1,0,1}
};
int maxi = -12323232;
void bfs() {


	while (!q.empty()) {

		coor now = q.front();
		q.pop();

		if (now.y == height-1) {
			if (now.sum > maxi) {
				maxi = now.sum;
			}
		}

		for (int i = 0; i < 3; i++) {

			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];


			if (ny < 0 || nx < 0 || ny >= height || nx >= width)continue;
			if (arr[ny][nx] == 0)continue;

			int nsum = now.sum + arr[ny][nx];

			q.push({ ny,nx,nsum });

		}


	}

}
int main() {
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			cin >> arr[i][j];


		}
	}

	q.push({ 0,0,arr[0][0]});
	bfs();

	cout << maxi;
	
}