#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct coor {
	int to;
	int cost;
};
bool operator<(coor a, coor b) {
	if (a.cost < b.cost)return false;
	if (a.cost > b.cost)return true;

	return false;
}
vector<coor> arr[20001];
int visited[20001];
int dist[20001];
int v, e;

void dijkstra(int st) {
	priority_queue<coor> pq;
	pq.push({ st,0 });

	for (int i = 1; i <= v; i++) {
		dist[i] = 2134567890;
	}

	dist[st] = 0;

	while (!pq.empty()) {
		coor now = pq.top();
		pq.pop();


		if (visited[now.to] == 1)continue;

		visited[now.to] = 1;

		for (int i = 0; i < arr[now.to].size(); i++) {

			int next = arr[now.to][i].to;

			int nextcost = dist[now.to]+arr[now.to][i].cost;

			if (dist[next] <= nextcost)continue;

			dist[next] = nextcost;

			pq.push({ next,nextcost });

		}

	}
	
	

}



int main() {
	cin >> v >> e;
	int k;
	cin >> k;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to,cost });

	}


	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 2134567890) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

}
	