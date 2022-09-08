//틀렸습니다
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

struct node {
	int y;
	int x;
};

int N; //맵의 크기(2^n)
int map[64][64]; //지도
int visited[64][64];
int di[2][4] = {
	-1,0,1,0,
	0,1,0,-1
};

void tornado(int L) {
	for (int y = 0; y < N; y += L) {
		for (int x = 0; x < N; x += L) {

			queue <int> q;
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < L; j++) {
					q.push(map[y + i][x + j]);
				}
			}

			for (int j = L - 1; j >= 0; j--) {
				for (int i = 0; i < L; i++) {
					map[y + i][x + j] = q.front();
					q.pop();
				}
			}
		}
	}
}

void fireball() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) continue;

			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + di[0][i];
				int nx = x + di[1][i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

				if (map[ny][nx] > 0) cnt++;
			}

			if (cnt < 3) map[y][x]--;
		}
	}
}

int main() {
	int n, Q;

	cin >> n >> Q;
	N = pow(2, n);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		int l;
		cin >> l;
		int L = pow(2, l);
		tornado(L);
		fireball();

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cout << map[y][x] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			sum += map[y][x];
		}
	}

	int maxcnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) continue;
			if (visited[y][x] == 1) continue;

			vector <node> v;
			v.push_back({y,x});
			visited[y][x] = 1;

			for(int i=0; i < v.size(); i++){

				for (int j = 0; j < 4; j++) {
					int ny = v[i].y + di[0][j];
					int nx = v[i].x + di[1][j];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (map[ny][nx] == 0) continue;
					if (visited[ny][nx] == 1) continue;

					v.push_back({ ny,nx });
					visited[ny][nx] = 1;
				}
			}

			maxcnt = max(maxcnt, int(v.size()));
		}
	}
	
	cout << sum << "\n" << maxcnt;
}