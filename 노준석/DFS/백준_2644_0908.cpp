#include <iostream>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int n, m;
int startNode, endNode;
int visited[101];
vector<int> v[101];
vector<int> path;
int min_path = 2134567890;
int cnt = 0;

void dfs(int now) {
	if (now == endNode) {
		min_path = min(min_path, cnt);
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (visited[next]) continue;

		visited[next] = 1;
		path.push_back(next);
		cnt += 1;
		dfs(next);
		visited[next] = 0;
		path.pop_back();
		cnt -= 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> startNode >> endNode;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	path.push_back(startNode);
	visited[startNode] = 1;
	dfs(startNode);
	
	if (min_path == 2134567890) cout << -1;
	else cout << min_path;

	return 0;
}