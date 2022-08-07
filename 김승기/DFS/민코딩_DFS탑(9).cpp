#include <iostream>
#include <vector>
using namespace std;
int n, m, x;
vector<int> arr[100001];
vector<int> revarr[100001];
int visited[100001];
int revvisited[100001];
vector<int> path;
vector<int> revpath;
void dfs(int now) {

	for (int i = 0; i < arr[now].size(); i++) {

		int next = arr[now][i];

		if (visited[next] == 1)continue;
		
		path.push_back(next);
		visited[next] = 1;
		dfs(next);
	}

}

void revdfs(int now) {

	for (int i = 0; i < revarr[now].size(); i++) {

		int next = revarr[now][i];

		if (revvisited[next] == 1)continue;

		revpath.push_back(next);
		revvisited[next] = 1;
		revdfs(next);
	}
}

int main() {

	cin>> n >> m >> x;
	for (int i = 0; i < m; i++) {	
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		revarr[to].push_back(from);
	}

	if (arr[x].size() > 0) {
		
		visited[x] = 1;
		dfs(x);

		revvisited[x] = 1;
		revdfs(x);
		int pathlen = path.size();
		int rpathlen = revpath.size();

		cout << rpathlen + 1 << "\n" << n - pathlen;
	}
	else {

		cout<< 1<<"\n"<<n;
	}

}