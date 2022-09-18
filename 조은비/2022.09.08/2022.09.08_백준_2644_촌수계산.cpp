// 맞았습니다!! 2024KB 0ms
#include <iostream>
#include <vector>

using namespace std;

vector <int> v[101];
int visited[101];
int ans = -1;

void func(int from, int to, int cnt) {
	visited[from] = 1;

	if (from == to) {
		ans = cnt;
		return;
	}

	for (int i = 0; i < v[from].size(); i++) {
		int next = v[from][i];
		if (visited[next] == 1) continue;

		func(next, to, cnt + 1);
	}
}

int main() {
	int N; //사람 수
	cin >> N;

	int from, to;
	cin >> from >> to;
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	func(from, to, 0);

	cout << ans;
	
}