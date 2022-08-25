#include <iostream>
#include <algorithm>
using namespace std;
long long a[1001];

int main() {


	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		sort(a, a + n);
		long long tempsum = 0;
		tempsum = a[0] + a[1];
		a[0] = tempsum;
		a[1] = tempsum;
	}

	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	cout << sum;
}