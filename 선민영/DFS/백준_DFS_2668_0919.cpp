#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int arr[102];
int dat[102];
int n;
priority_queue<int, vector<int>, greater<int>>q;

void dfs(int num) {
	if (dat[arr[num]] == 2)return;
	if (dat[arr[num]] == 1) {
		int k = num;
		while (1) {
			dat[k] = 2;
			q.push(k);
			k = arr[k];
			if (k == num)break;
		}
		return;
	}
	dat[arr[num]] = 1;
	dfs(arr[num]);
	if (dat[arr[num]] != 2)dat[arr[num]] = 0;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == arr[i]) {
			dat[i] = 2;
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	cout << q.size() << "\n";
	while (!q.empty()) {
		cout << q.top() << "\n";
		q.pop();
	}
}
