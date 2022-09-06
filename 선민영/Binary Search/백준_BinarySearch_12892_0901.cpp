#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
	long long price, happy;
};
bool cmp(Node a, Node b) {
	if (a.price < b.price)return true;
	if (a.price > b.price)return false;
	if (a.happy < b.happy)return true;
	if (a.happy > b.happy)return false;
	return false;
}
vector<Node>v;

int main() {
	int n;
	cin >> n;
	long long big = 0;
	long long mini;
	cin >> mini;
	for (int i = 0; i < n; i++) {
		long long price, happy;
		cin >> price >> happy;
		v.push_back({ price, happy });
		if (happy > big) big = happy;
	}
	sort(v.begin(), v.end(), cmp);
	int left = 0;
	int right = 0;
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].price - v[0].price >= mini) {
			right = i - 1;
			break;
		}
		if (i == v.size() - 1)right = n - 1;
		sum += v[i].happy;
	}
	long long maxval = 0;
	if (sum > maxval)maxval = sum;
	while (right != n - 1) {
		int k = left;
		while (1) {
			sum -= v[left].happy;
			left++;
			if (v[k].price != v[left].price) {
				break;
			}
		}
		while (right != n - 1) {
			right++;
			sum += v[right].happy;
			if (v[right].price - v[left].price >= mini) {
				sum -= v[right].happy;
				right--;
				break;
			}
		}
		if (sum > maxval)maxval = sum;
	}
	if (maxval == v[0].price)cout << big;
	else cout << maxval;
}