#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long arr[1001];
	int n, cnt;
	cin >> n >> cnt;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < cnt; i++) {
		long long k = arr[0] + arr[1];
		arr[0] = k;
		arr[1] = k;
		sort(arr, arr + n);

	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}cout << sum;
}