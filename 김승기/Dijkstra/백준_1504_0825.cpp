#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int to;
	int cost;
};
vector<edge> v[200000];
int dist[801];
int v1, v2;
int n, e;

bool operator<(edge a,edge b) {
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	return false;
}

int dijkstra(edge st, int en) {
	priority_queue<edge> pq;

	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	pq.push(st);
	dist[st.to] = st.cost;
	

	while (!pq.empty()) {
		int now = pq.top().to;
		int nowdist = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int nextdist = v[now][i].cost;

			if (dist[next] < nextdist + dist[now])continue;


			dist[next] = nextdist + dist[now];
			pq.push({ next,dist[next] });
		}

	}

	return dist[en];
}


int main() {

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({to,cost});
		v[to].push_back({from,cost});

	}

	cin >> v1 >> v2;

	int v1dist = 0;
	int minans = 2134567890;

	// 1 -> v1 -> v2 ->n
	// 1 -> v1
	v1dist = dijkstra({ 1,0 },v1);

	// v1 -> v2
	int v2dist = 0;
	v2dist = dijkstra({ v1,dist[v1] },v2);

	// v2 -> n
	int ans = 0;
	ans = dijkstra({ v2,dist[v2] },n);
	//cout << ans;
	minans = min(minans, ans);


	// 1 -> v2 -> v1 ->n
	// 1 -> v2
	v1dist = 0;
	v2dist = dijkstra({ 1,0 }, v2);

	// v2 -> v1
	v2dist = 0;
	v1dist = dijkstra({ v2,dist[v2] }, v1);

	// v1 -> n
	ans = 0;
	ans = dijkstra({ v1,dist[v1] }, n);
	minans = min(minans, ans);
	
	if (dist[n] == 2134567890) {
		cout << -1;
	}
	else {
		cout << minans;
	}
}