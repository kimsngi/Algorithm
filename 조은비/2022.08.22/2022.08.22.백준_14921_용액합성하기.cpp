#include<iostream>

using namespace std;

int water[100000];

int ab(int x) {
	if (x < 0) return -x;
	else return x;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> water[i];
	}

	int minSum = 200000000;

	int left = 0; int right = n - 1;
	while (left < right) {
		int sum = water[left] + water[right];
		if (ab(sum) < ab(minSum)) minSum = sum;

		if (sum > 0) {
			right--;
		}
		else if (sum < 0) {
			left++;
		}
		else break;
	}

	cout << minSum;
}