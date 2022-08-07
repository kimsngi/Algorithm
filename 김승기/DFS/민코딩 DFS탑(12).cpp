#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct coor {
	int y;
	int x;
};
int n, m;
int map[100][100];
int visited[100][100];
vector<coor> path;
priority_queue<int> ans;
int di[2][4] = {
	{-1,1,0,0},
	{0,0,-1,1}
};
void dfs(coor st) {
	for (int i = 0; i < 4; i++) {
		int ny = st.y + di[0][i];
		int nx = st.x + di[1][i];

		if (map[ny][nx] != 1)continue;
		if (visited[ny][nx] == 1)continue;

		path.push_back({ ny,nx });
		map[ny][nx] = 2;
		dfs({ ny,nx });
	}

}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				coor st;
				st.y = i;
				st.x = j;

				dfs(st);

				int ymin = n;
				int	ymax = 0;
				int xmin = m;
				int xmax = 0;
				for (int i = 0; i < path.size(); i++) {
					if (path[i].y < ymin) {
						ymin = path[i].y;
					}
					if (path[i].y > ymax) {
						ymax = path[i].y;
					}
					if (path[i].x < xmin) {
						xmin = path[i].x;
					}
					if (path[i].x > xmax) {
						xmax = path[i].x;
					}
				}

				ans.push(2 * ((ymax - ymin+2) + (xmax - xmin+2)));
				path.clear();
			}
		}
	}

	int out = ans.top();
	cout << out;
	
}