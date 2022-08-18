#include <iostream>
#include <vector>
#include <queue>
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
int n, e;
int start;
struct Node {
	int to;
	int cost;
};
bool operator< (Node a, Node b) {
	if (a.cost < b.cost)
		return false;
	if (a.cost > b.cost)
		return true;
	return false;
}
vector<Node>v[20001];
priority_queue<Node>q;
int visited[20001];
int dist[20001];
void method() {
	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		if (visited[now.to] == 1)continue;
		visited[now.to] = 1;
		for (int i = 0; i < v[now.to].size(); i++) {
			Node next = v[now.to][i];
			if (dist[next.to] < dist[now.to] + next.cost)continue;
			dist[next.to] = dist[now.to] + next.cost;
			q.push({ next.to, dist[next.to] });
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> e >> start;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	q.push({ start, 0 });
	dist[start] = 0;
	method();
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 2134567890) cout << "INF" << "\n";
		else  cout << dist[i] << "\n";
	}
} 
