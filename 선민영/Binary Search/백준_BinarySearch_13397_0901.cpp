#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[5001];
int main() {
	int n, m;
	cin >> n >> m;
	int big = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > big)big = arr[i];
	}
	int mini = 0;
	int ans = 2134567890;
	while (mini<=big) {
		int middle = (big + mini)/2;
		int k = 0;
		int cnt = 1;
		while (k != n-1) {
			int sum = 0;
			int maxnum = 0;
			int minnum = 2134567890;
			for (int i = k; i < n; i++) {
				if (arr[i] > maxnum)maxnum = arr[i];
				if (arr[i] < minnum)minnum = arr[i];
				sum = maxnum - minnum;
				if (sum > middle) {
					cnt++;
					k = i;
					break;
				}
				if (i == n - 1)k = i;
			}
			
		}
		if (cnt > m) {
			mini = middle + 1;
		}
		else if (cnt <= m) {
			if (middle < ans) {
				ans = middle;
			}
			big = middle - 1;
		}
	}cout << ans;
}