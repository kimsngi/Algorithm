#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int n, one, two, num;
vector<int>v[101];
int visited[101] = { 0, };
struct Node {
	int node, num;
};
int final = 0;

void bfs(int node) {
	queue<Node>q;
	q.push({ node, 0 });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (visited[now.node] == 1)continue;
		visited[now.node] = 1;
		if (now.node == two) final = now.num;
		for (int i = 0; i < v[now.node].size(); i++) {
			q.push({ v[now.node][i], now.num + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie();
	cout.tie();

	cin >> n >>one >>two>>num;
	for (int i = 0; i < num; i++) {
		int parent, child;
		cin >> parent >> child;
		v[parent].push_back(child);
		v[child].push_back(parent);
	}
	bfs(one);
	if (final == 0)cout << -1;
	else cout << final;
}
