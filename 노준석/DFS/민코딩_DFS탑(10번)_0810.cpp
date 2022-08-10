#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int N, startNode, endNode;

struct Edge {
    int node;
    int cost;
};

// 인접 리스트로 풀기
vector<Edge> v[100001];
int visited[100001];

vector<int> path;
// A에서 B로 가는 거리 계산
// 그 거리 중 가장 긴 길이 빼기

int my_distance = 0;
int result_distance = 0;
int max_dist = -2134567890;
int temp_dist = 0;

void dfs(Edge start) {
    int now = start.node;
    // 기저 조건
    if (now == endNode) {
        /*for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";*/
        // 1 2 5 9 되어 있음(path)

        for (int i = 0; i < path.size() - 1; i++) {
            for (int j = 0; j < v[path[i]].size(); j++) {
                temp_dist = 0;
                if (v[path[i]][j].node == path[i+1]) {
                    temp_dist = v[path[i]][j].cost;
                }
                if (temp_dist > max_dist) max_dist = temp_dist;
            }
        }
        result_distance = my_distance;
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        Edge next = v[now][i];

        if (visited[next.node]) continue;

        visited[next.node] = 1;
        my_distance += next.cost;
        path.push_back(next.node);

        dfs(next);

        path.pop_back();
        visited[next.node] = 0;
        my_distance -= next.cost;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> startNode >> endNode;
    for (int i = 0; i < N - 1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to,cost });
        v[to].push_back({ from,cost });
    }
    if (startNode == endNode) {
        cout << 0;
        return 0;
    }
    path.push_back(startNode);
    visited[startNode] = 1;
    dfs({startNode,0});
    cout << result_distance - max_dist << "\n";
    

}