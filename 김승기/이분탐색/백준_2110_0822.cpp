#include <iostream>
#include <algorithm>
using namespace std;
int home[200000];
int diff[200000];
int sum[200000];
int main() {
	int n, c;
	cin >> n >> c;
	int maxhome = 0;
	for (int i = 0; i < n; i++) {
		cin >> home[i];
		maxhome = max(maxhome, home[i]);
	}

	sort(home, home + n);

	for (int i = 0; i < n - 1; i++) {
		diff[i] = home[i + 1] - home[i];
	}

	int left = 1;
	int right = maxhome;
	int ans = 0;
	int cnt = 1;
	while (left <= right) {
		int mid = (left + right) / 2;

		for (int i = 0; i <= cnt; i++) {
			sum[i] = 0;
		}
		cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (sum[cnt] < mid) {

				sum[cnt] += diff[i];
			}
			else {
				cnt++;
				sum[cnt] += diff[i];
			}

			if (sum[cnt] >= mid && i == n - 2) {
				cnt++;
			}
		}

		if (cnt >= c - 1) {
			ans = mid;
			left = mid + 1;
		}
		if (cnt < c - 1) {
			right = mid - 1;
		}

	}

	cout << ans;

}