#include <iostream>
using namespace std;
int arr[1001];
int dat[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int k = 1;
	int sum = 0;
	while (1) {
		cout << k << " ";
		dat[k] = 1;
		sum++;
		if (sum == n)break;
		int num = arr[k];
		int cnt = 0;
		if (num > 0) {
			for (int i = k + 1; i <= n; i++) {
				if (dat[i] == 0)cnt++;
				if (cnt == num) {
					k = i;
					break;
				}
			}
			if (cnt != num) {
				while (1) {
					for (int i = 1; i <= n; i++) {
						if (dat[i] == 0)cnt++;
						if (cnt == num) {
							k = i;
							break;
						}
					}
					if (cnt == num)break;
				}
			}
		}
		if (num < 0) {
			for (int i = k - 1; i >= 1; i--) {
				if (dat[i] == 0)cnt++;
				if (cnt == abs(num)) {
					k = i;
					break;
				}
			}
			if (cnt != abs(num)) {
				while (1) {
					for (int i = n; i >= 1; i--) {
						if (dat[i] == 0)cnt++;
						if (cnt == abs(num)) {
							k = i;
							break;
						}
					}
					if (cnt == abs(num))break;
				}
			}
		}
	}
}