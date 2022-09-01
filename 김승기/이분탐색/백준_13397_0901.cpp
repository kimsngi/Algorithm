#include <iostream>
using namespace std;
int number[5000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	int maxi = 0;
	int mini = 20000;
	for (int i = 0; i < n; i++) {
		if (maxi < number[i]) maxi = number[i];
		if (mini > number[i]) mini = number[i];
	}

	int maxdiff = maxi -mini;

	int left = 0;
	int right = maxdiff;
	int ans = 0;

	while (left <= right) {

		int mid = (left + right) / 2;
		int teamcnt = 1;
		int maxval = 0;
		int minval = 10001;
		int maxdiff = 0;
		int temp = 0;

		for (int i = 0; i < n; i++) {

			maxval = max(maxval, number[i]);
			minval = min(minval, number[i]);

			temp = maxval - minval;

			if (temp > mid) {

				maxval = 0;
				minval = 10001;
				teamcnt++;
				i = i - 1;
			}
			else {
				maxdiff = max(temp, maxdiff);

			}
		}

		if (teamcnt <= m) {
			ans = maxdiff;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}

	cout << ans;

}