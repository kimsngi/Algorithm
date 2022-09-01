#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct coor {
	int y;
	int x;
};
int map[50][50];
int visited[50][50];
int cnt;
int flag;
queue<coor> q;
vector<int> sum;
int dr[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
int n, l, r;

int bfs(coor st,int teamcnt) {
	int tempsum = 0;
	int cnt = 0;

	while (!q.empty()) {
		coor now = q.front();
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[0][i];
			int nx = now.x + dr[1][i];

			int diff = abs(map[ny][nx] - map[now.y][now.x]);

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (diff<l || diff >r)continue;
			if (visited[ny][nx] >0)continue;

			visited[ny][nx] = teamcnt;
			cnt++;
			tempsum += map[ny][nx];
			q.push({ ny,nx });

		}

	}

	

	if (tempsum > map[st.y][st.x]) {
		sum.push_back(tempsum);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == teamcnt) {
					map[i][j] = tempsum / cnt;
				}

			}
		}
	}
	return tempsum;
}


int main() {

	
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			
		}
	}
	int ans = 0;
	while (flag==0) {
		flag = 1;
		int teamcnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] >0)continue;
				q.push({ i,j });
				if (bfs({ i,j },teamcnt) > map[i][j]) {
					teamcnt++;
					flag = 0;
					
				}
			}
		}

		ans++;
		memset(visited, 0, sizeof(visited));

	}

	cout << ans - 1;
}