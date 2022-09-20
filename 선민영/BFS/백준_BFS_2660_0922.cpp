#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int>v[51];
int visited[51];
struct Node {
	int num, cnt;
};
int maxval;
vector<Node>check;
bool cmp(Node a, Node b) {
	if (a.cnt > b.cnt)return false;
	if (a.cnt < b.cnt)return true;
	if (a.num > b.num)return false;
	if (a.num < b.num)return true;
	return false;
}

void bfs(int i) {
	maxval = 0;
	queue<Node>q;
	q.push({ i, 0 });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (maxval < now.cnt)maxval = now.cnt;
		for (int i = 0; i < v[now.num].size(); i++) {
			if (visited[v[now.num][i]] ==1)continue;
			visited[v[now.num][i]] = 1;
			q.push({ v[now.num][i], now.cnt + 1 });
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	while (1) {
		int one, two;
		cin >> one >> two;
		if (one == -1)break;
		v[one].push_back(two);
		v[two].push_back(one);
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = 1;
		bfs(i);
		check.push_back({ i, maxval });
		memset(visited, 0, sizeof(visited));
	}
	sort(check.begin(), check.end(), cmp);
	int candidate = 1;
	Node final = check[0];
	for (int i = 1; i < check.size(); i++) {
		if (check[i].cnt == final.cnt)candidate++;
		else break;
	}
	cout << final.cnt <<" "<< candidate;
	cout << "\n";
	for (int i = 0; i < candidate; i++) {
		cout << check[i].num<<" ";
	}
}