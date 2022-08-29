#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Edge {
    int num;
    int cost;
};

bool operator<(Edge a, Edge b) {
    if (a.cost > b.cost) return false;
    if (a.cost < b.cost) return true;

    return false;
}

int cntNode, cntEdge;
vector<Edge> v[801];
int dist[801];
int visited[801];
int v1, v2; // 반드시 거쳐야 하는 두 개의 서로 다른 정점

priority_queue<Edge> pq;
int MAX_DIST = 2134567890;

int dijkstra(int startNode,int endNode) {
    // dist 세팅
    for (int i = 0; i <= cntNode; i++) {
        dist[i] = MAX_DIST;
    }
    dist[startNode] = 0;

    pq.push({ startNode,0 });

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();

        /*if (visited[now.num]) continue;
        visited[now.num] = 1;*/

        for (int i = 0; i < v[now.num].size(); i++) {
            Edge next = v[now.num][i];

            int nextCost = next.cost;

            if (dist[now.num] + nextCost > dist[next.num]) continue;

            dist[next.num] = nextCost + dist[now.num];
            
            pq.push({ next.num,dist[next.num] });
        }
    }
    
    return dist[endNode];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> cntNode >> cntEdge;
    for (int i = 0; i < cntEdge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        // 양방향 연결
        v[from].push_back({ to,cost });
        v[to].push_back({ from,cost });
    }

    // 지나는 두 정점
    cin >> v1 >> v2;

    long long dist1, dist2, dist3;
    long long dist4, dist5, dist6;
    // 1. 1 v1 v2 N 거리
    dist1 = dijkstra(1, v1);
    dist2 = dijkstra(v1, v2);
    dist3 = dijkstra(v2, cntNode);
    
    // 2. 1 v2 v1 N 거리
    dist4 = dijkstra(1, v2);
    dist5 = dijkstra(v2, v1);
    dist6 = dijkstra(v1, cntNode);

    // 갈 수 있는 경로가 없는 경우
    long long result = min(dist1 + dist2 + dist3, dist4 + dist5 + dist6);
    if (result >= MAX_DIST)
        cout << -1;
    else
        cout << result;
}