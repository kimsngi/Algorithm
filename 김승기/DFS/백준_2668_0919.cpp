#include <iostream>	
#include <vector>
#include <algorithm>
using namespace std;
int number[101];
int visited[101];
vector<int> v[101];
vector<int> path;
vector<int> ansnum;
int ans;
int flag;
void dfs(int st,int now,int cnt) {

	if (now == st && cnt != 0) {
		ans += cnt;
		flag = 1;
		return;
	}

	//v[st] 크기는 무조건 1
	int next = v[now][0];

	if (visited[now] == 1)return;

	path.push_back(now);
	visited[now] = 1;
	dfs(st,next,cnt+1);

}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
		v[i].push_back(number[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1)continue;

		dfs(i,i,0);

		if (!flag) {//집합 불가능한 경우
			for (int i = 0; i < path.size(); i++) {
				visited[path[i]] = 0;
			}
			path.clear();

		}else{//집합 가능한 경우
			for (int i = 0; i < path.size(); i++) {
				ansnum.push_back(path[i]);
			}
			path.clear();
			flag = 0;
		}
	}

	sort(ansnum.begin(), ansnum.end());

	cout << ans<<"\n";
	for (int i = 0; i < ansnum.size(); i++) {
		cout << ansnum[i] << "\n";
	}
}