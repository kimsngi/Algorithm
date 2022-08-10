#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int to;
	int length;
};
vector<edge> v[100001];
int n, a, b;
int sum;
int visited[100001];
int mini = 2134567890;
int maxi = -2134567890;
vector<int> lenpath;

void dfs(int now) {

	if (now == b) {
		if (lenpath.size() == 0) mini = 0;
		else if(lenpath.size() == 1) {
			mini = sum;
			return;
		}
		else {
			for (int i = 0; i < lenpath.size(); i++) {
				if (maxi < lenpath[i])maxi = lenpath[i];
			}
			sum = sum - maxi;
			if (sum < mini)mini = sum;
			return;
		}
	}
	
	for (int i = 0; i < v[now].size(); i++) {

		int next = v[now][i].to;
		int nextlength = v[now][i].length;
		if (visited[next] == 1)continue;

		lenpath.push_back(nextlength);
		visited[next] = 1;
		sum += nextlength;
		dfs(next);
		sum -= nextlength;
		lenpath.pop_back();

	}


}

int main() {
	
	cin >> n >> a >> b;
	for (int i = 0; i < n-1; i++) {
		int from, to, length;
		cin >> from >> to >> length;
		v[from].push_back({ to,length });
		v[to].push_back({ from,length });

	}

	dfs(a);

	cout << mini;

}