#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left = 0; 
	int right = n - 1;
	int sum = 0;
	long long maxval = -212121212123456;
	long long maxval2 = 212121212123456;
	sum = arr[right] + arr[left];
	while (right != left) {
		if (sum < 0) {
			if (sum > maxval) {
				maxval = sum;
			}
			sum -= arr[left];
			left++;
			sum += arr[left];
		}
		else if (sum > 0) {
			if (sum < maxval2) {
				maxval2 = sum;
			}
			sum -= arr[right];
			right--;
			sum += arr[right];
		}
		else {
			break;
		}

	}
	if (sum == 0)cout << 0;
	else if (maxval == 0 || maxval2 == 0)cout << 0;
	else if (maxval * (-1) > maxval2) cout << maxval2;
	else if (maxval * (-1) == maxval2) cout << maxval2;
	else cout << maxval;
}
