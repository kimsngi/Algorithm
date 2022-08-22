#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		long long t; 
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	long long ans=0;
	int left = 0;
	long long right = v[n-1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		int p = 0;
		int q = 1;
		int cnt = 1;
		while (1) {
			if (p + q >= n)break;
			if (v[p + q] - v[p] >= mid) cnt++;
			else if (v[p + q] - v[p] < mid) {
				while (1) {
					q++;
					if (p + q >= n)break;
					else if (v[p + q] - v[p] >= mid) {
						cnt++;
						break;
					}
				}
			}
			p += q;
			q = 1;
		}
		if (cnt >= c) {
			left = mid + 1;
			ans = mid;
		}
		if (cnt < c) {
			right = mid - 1;
		}

	}cout << ans;
}