#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Node {
	int to;
	int cost;
};
struct Edge {
	int from;
	int to;
};
vector<Node>v[100002];
queue<Edge>q;
vector<int>path;
int dist[100002]={0,};
int visited[100002]={0,};
int k = 0;
int t = 0;
int n, first, second;
int maxd = 0;
void dfs(Node now) {
	if (now.to == second) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] > maxd)maxd = path[i];
		}
		return;
	}
	visited[now.to] = 1;
	for (int i = 0; i < v[now.to].size(); i++) {
		Node next = v[now.to][i];
		if (visited[next.to] == 1)continue;
		visited[next.to] = 1;
		dist[next.to] = dist[now.to] + next.cost;
		q.push({ now.to,next.to });
		path.push_back(next.cost);
		dfs({ next.to, dist[next.to] });
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> first >> second;
	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	if (first != second) {
		dfs({ first, 0 });
	}
	
	cout << dist[second]-maxd;
}