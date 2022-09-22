#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
vector<int> v[51];
queue<int> q;
int cnt[51];
int visited[51];
int n;
vector<int> score[50];
void bfs(int st) {
	


	while (!q.empty()) {
		
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {

			int next = v[now][i];
			if (visited[next] == 1)continue;



			visited[next] = 1;
			cnt[next] = cnt[now] + 1;
			q.push(next);

		}

	}
	int maxcnt = -1;
	for (int i = 1; i <= n; i++) {
		
		maxcnt = max(maxcnt, cnt[i]);
	}
	score[maxcnt].push_back(st);

}


int main() {
	
	cin >> n;
	int a = 0;
	int b = 0;
	while (1) {

		cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		q.push(i);
		memset(cnt, 0, sizeof(cnt));
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		bfs(i);
	}

	for (int i = 1; i <= n - 1; i++) {
		if (score[i].size() == 0)continue;

		sort(score[i].begin(), score[i].end());

		cout << i << " " << score[i].size() << "\n";

		for (int j = 0; j < score[i].size(); j++) {
			cout << score[i][j] << " ";
		}
		break;
	}
}