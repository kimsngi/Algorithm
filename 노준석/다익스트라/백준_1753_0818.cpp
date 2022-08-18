#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Edge {
    int num;
    int cost;
};

int cntNode, cntEdge;
int startNode;
vector<Edge> v[20001];
int visited[20001];
int dist[20002];

priority_queue<Edge> pq;

bool operator<(Edge a, Edge b) {
    if (a.cost < b.cost) return false;
    if (a.cost > b.cost) return true;

    if (a.num < b.num) return false;
    if (a.num > b.num) return true;

    return false;
}

void dijkstra(int start) {
    for (int i = 0; i <= 20001; i++) {
        dist[i] = 2147483647;
    }
    dist[start] = 0;
    pq.push({ start,0 });

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (visited[now.num]) continue;

        visited[now.num] = 1;

        for (int i = 0; i < v[now.num].size(); i++) {
            Edge next = v[now.num][i];

            int nextNode = next.num;
            int nextCost = next.cost;

            if (dist[now.num] + nextCost > dist[nextNode]) continue;

            dist[nextNode] = nextCost + dist[now.num];
            pq.push({ nextNode,dist[nextNode] });
        }
    }
    for (int i = 1; i <= cntNode; i++) {
        if (dist[i] == 2147483647) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> cntNode >> cntEdge;
    cin >> startNode;
    for (int i = 0; i < cntEdge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to,cost });
    }
    dijkstra(startNode);
}