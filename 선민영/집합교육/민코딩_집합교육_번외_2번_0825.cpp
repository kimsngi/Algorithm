#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;
struct Node {
	int num, ratio;
};
struct Edge {
	int num, money, left;
};
bool operator < (Node a, Node b) {
	if (a.ratio < b.ratio)
		return true;
	if (a.ratio > b.ratio)
		return false;
	if (a.num < b.num)
		return false;
	if (a.num > b.num)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int ms, ma;
		cin >> ms >> ma;
		int n, l;
		cin >> n >> l;
		int arr[16][16];
		priority_queue<Node>qq;
		priority_queue<Edge>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l+1; j++) {
				cin >> arr[i][j];
			}
		}
		int final = ms + l * ma;
		int p = 0;
		while (p < l) {
			for (int i = 0; i < n; i++) {
				if (arr[i][p + 1] - arr[i][p] > 0) {
					int ratio = arr[i][p + 1] - arr[i][p];
					qq.push({ arr[i][p], ratio });
				}
				else qq.push({ arr[i][p], 0 });
			}
			int checkms = ms;
			int money=0;
			while(!qq.empty()){
				if (qq.top().ratio != 0) {
					Node now = qq.top();
					qq.pop();
					if (checkms < now.num)continue;
					int num = checkms / now.num;
					money += num * now.ratio;
					checkms -= num*now.num;
				}
				else qq.pop();
			}
			ms += money + ma;
			p++;
		}
		cout << "#" << k + 1 << " " << ms-final << "\n";
		
	}
}