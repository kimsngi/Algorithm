// 시간 초과

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int score;
};
vector <Edge> v[20001];

int visited[20001];
int V, E;
int sum;

void dfs(int from, int to, int score) {

    visited[from] = 1;

    if (from == to) {
        sum = min(sum, score);
        return;
    }

    for (int i = 0; i < v[from].size(); i++) {
        int next = v[from][i].to;
        if (visited[next] == 1) continue;

        dfs(next, to, score + v[from][i].score);

        visited[next] = 0;
    }

    return;
}

int main() {

    cin >> V >> E;

    int from;
    cin >> from;

    for (int i = 0; i < E; i++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        v[from].push_back({ to, distance });
    }

    for (int i = 1; i <= V; i++) {
        sum = 1234567890;

        dfs(from, i, 0);

        if (sum == 1234567890) cout << "INF\n";
        else cout << sum << "\n";
    }
}