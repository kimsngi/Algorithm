#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;
int n, e;
int one, two;
struct Node {
	int to, cost;
};

vector<Node>v[801];
priority_queue<Node>q;
bool operator < (Node a, Node b) {
	if (a.cost < b.cost)
		return true;
	if (a.cost > b.cost)
		return false;
	return false;
}
int dist[801] = { 0, };
void dijkstra(int from) {
	dist[from] = 0;
	q.push({ from, 0 });
	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		int sized = v[now.to].size();
		for (int i = 0; i < sized; i++) {
			Node next = v[now.to][i];
			if (dist[next.to] < dist[now.to] + next.cost)continue;
			dist[next.to] = dist[now.to] + next.cost;
			q.push({ next.to, dist[next.to] });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	cin >> one >> two;
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	int sum = 0;
	int sflag = 0;
	dijkstra(1);
	if (dist[one] == 2134567890)sflag = 1;
	sum += dist[one];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dijkstra(one);
	if (dist[two] == 2134567890)sflag = 1;
	sum += dist[two];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dijkstra(two);
	if (dist[n] == 2134567890)sflag = 1;
	sum += dist[n];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}

	int cnt = 0;
	int cflag = 0;
	dijkstra(1);
	if (dist[two] == 2134567890)cflag = 1;
	cnt += dist[two];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dijkstra(two);
	if (dist[one] == 2134567890)cflag = 1;
	cnt += dist[one];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dijkstra(one);
	if (dist[n] == 2134567890)cflag = 1;
	cnt += dist[n];

	if (cflag == 1 && sflag == 1)cout << -1;
	else if (cflag == 1 && sflag == 0)cout << sum;
	else if (cflag == 0 && sflag == 1)cout << cnt;
	else if (sum < cnt)cout << sum;
	else cout << cnt;
}