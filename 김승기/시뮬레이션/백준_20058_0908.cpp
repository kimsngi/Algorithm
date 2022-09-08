#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;
struct coor {
	int y;
	int x;
};
int N, Q;
int A[64][64];
int tempA[64][64];
int L[1000];
int boxsize;
int dvisited[64][64];
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int mapsize;

queue<coor> deice;

void rotate(coor st){

	for (int i = st.y; i <st.y+ boxsize; i++) {
		for (int j = st.x; j < st.x+boxsize; j++) {

			tempA[i-st.y][j-st.x] = A[i][j];
		}
	}

	for (int i = 0; i < boxsize; i++) {
		for (int j = 0; j < boxsize; j++) {
			A[j +st.y][boxsize - 1 - i +st.x] = tempA[i][j];
		}
	}
}

void icecheck(coor st) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = st.y + dr[0][i];
		int nx = st.x + dr[1][i];

		if (ny < 0 || nx < 0 || ny >= mapsize || nx >= mapsize)continue;
		if (A[ny][nx] == 0)continue;

		cnt++;
	}
	if (cnt < 3) {
		deice.push(st);
	}

}

int bfs(coor st) {
	queue<coor> q;
	q.push(st);
	dvisited[st.y][st.x] = 1;
	int asize = 1;

	while (!q.empty()) {
		coor now = q.front();
		q.pop();

		
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];

			if (ny < 0 || nx < 0 || ny >= mapsize || nx >= mapsize)continue;
			if (dvisited[ny][nx]==1)continue;
			if (A[ny][nx] == 0)continue;
			
			asize++;
			dvisited[ny][nx] = 1;
			q.push({ ny,nx });

		}
	
	}

	return asize;

}

int main() {

	cin >> N >> Q;
	mapsize = pow(2, N);
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {

		cin >> L[i];
	}

	for (int i = 0; i < Q; i++) {
		
		boxsize =pow(2, L[i]);

		for (int i = 0; i < mapsize; i=i+boxsize) {
			for (int j = 0; j < mapsize; j = j + boxsize) {

				rotate({ i,j });
			}
		}

		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				
				icecheck({i,j});
			}
		}

		while (!deice.empty()) {
			coor now = deice.front();
			deice.pop();

			if (A[now.y][now.x] == 0)continue;
			A[now.y][now.x]--;
		}

	}
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			ans1 += A[i][j];
		}
	}
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (dvisited[i][j] == 1)continue;
			if (A[i][j] == 0)continue;
			
			ans2 = max(bfs({ i,j }),ans2);
		}
	}

	cout << ans1 << "\n" << ans2;


}