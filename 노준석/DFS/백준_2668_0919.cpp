#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;

int N;
int visited[101];
int numbers[101];
vector<int> result;

// 1 -> 3, 3 -> 1의 경우, 사이클 존재
int start = -1;

void dfs(int node) {
	// 방문 처리
	if (!visited[node]) {
		visited[node] = 1;
		dfs(numbers[node]);
	}
	// 만약 방문했고, 돌아오는 사이클이 존재하면 시작점을 결과에 추가
	else if (node == start) {
		result.push_back(start);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> numbers[i];
	}
	
	for (int i = 1; i <= N; i++) {
		start = i;
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}