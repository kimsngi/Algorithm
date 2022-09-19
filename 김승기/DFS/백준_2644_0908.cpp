#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101];
int visited[101];
int n, a, b,ans,flag;

void dfs(int st,int level) {

	if (st == b) {
		flag = 1;
		ans = level;
		return;
	}

	int now = st;
	for (int i = 0; i < v[now].size(); i++) {

		int next = v[now][i];

		if (visited[next] == 1)continue;

		visited[next] = 1;
		dfs(next,level + 1);
		visited[next] = 0;
	}

}

int main() {

	cin >> n >> a >> b;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	visited[a] = 1;
	dfs(a,0);

	if (!flag) {
		cout << -1;
	}
	else {

		cout << ans;
	}
	
}