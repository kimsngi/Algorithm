#include <iostream>
#include <algorithm>
using namespace std;
int sensor[10000];
int diff[10000];



int main() {
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> sensor[i];
	}

	sort(sensor, sensor + n);

	for (int i = 0; i < n-1; i++) {
		diff[i] = sensor[i+1] - sensor[i];
	}

	sort(diff, diff + n - 1);

	int sum = 0;
	for (int i = 0; i < (n - 1) - (k - 1); i++) {
		sum += diff[i];
	}
		
	cout << sum;


}