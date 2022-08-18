#include <iostream>
#include <vector>

using namespace std;

struct robot {
	int to;
	int distance;
};
vector <robot> robo[100001];
vector <int> path;
int visited[100001];

int flag = 0;
void dfs(int from, int to) {
	if (from == to) {
		flag = 1;
		return;
	}

	for (int i = 0; i < robo[from].size(); i++) {
		robot next = robo[from][i];
		if (visited[next.to]) continue;

		visited[next.to] = 1;
		path.push_back(next.distance);
		dfs(next.to, to);
		if (flag) break;
		path.pop_back();
	}
}

int main() {
	int n, robot1, robot2;
	cin >> n >> robot1 >> robot2;
	for (int i = 1; i < n; i++) {
		int from, to, distance;
		cin >> from >> to >> distance;
		robo[from].push_back({ to,distance });
		robo[to].push_back({ from, distance });
	}

	dfs(robot1, robot2);

	int max = 0;
	int sum = 0;
	for (int i = 0; i < path.size(); i++) {
		if (max < path[i]) max = path[i];
		sum += path[i];
	}

	cout << sum - max;
}