#include <iostream>
#include <vector>
#include <queue>
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

struct coord {
	int x;
	int y;
};

int board[301][301];
int visited[301][301];

queue<coord> q;

coord knight, target;

int n,t;
int temp = 0;

int dx[8] = { -2,-1,-2,-1,2,1,2,1 };
int dy[8] = { 1,2,-1,-2,-1,-2,1,2 };

void bfs(coord node) {
	q.push(node);
	visited[node.x][node.y] = 1;
	

	while (!q.empty()) {
		coord now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = 1;
			board[nx][ny] = board[now.x][now.y] + 1;

			if (nx == target.x && ny == target.y) temp = board[nx][ny];
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		temp = 0;
		cin >> n;
		
		cin >> knight.x >> knight.y;
		cin >> target.x >> target.y;

		if (knight.x == target.x && knight.y == target.y) temp = 0;
		else {
			bfs(knight);
		}

		cout << temp << "\n";

		//while (!q.empty()) q.pop();
		for (int i = 0; i < 301; i++) {
			for (int j = 0; j < 301; j++) {
				visited[i][j] = 0;
				board[i][j] = 0;
			}
		}
		
	}


	return 0;
}