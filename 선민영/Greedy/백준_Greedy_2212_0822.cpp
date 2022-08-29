#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v;
vector<int>minused;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-1; i++) {
		minused.push_back(v[i + 1] - v[i]);
	}
	int sum = 0;
	sort(minused.begin(), minused.end());
	for (int i = 0; i < n - k; i++) {
		sum += minused[i];
	}
	cout << sum;
}