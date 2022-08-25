#include <iostream>
using namespace std;
int sol[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sol[i];
	}


	int left = 0;
	int right = n - 1;
	int sum = -213456789;
	int minimum = 2134567890;
	int sign = 0;

	while (left < right) {

		sum = sol[left] + sol[right];

		if (sum > 0) {
			if (minimum > abs(sum)) {
				minimum = abs(sum);
				sign = 1;
			}
			right--;
		}
		else if (sum< 0) {
			if (minimum > abs(sum)) {
				minimum = abs(sum);
				sign = -1;
			}
			left++;
		}
		else {
			cout << sum;
			break;
		}


	}

	if (sum != 0){

		if (sign == -1) {
			cout << -1 * minimum;
		}
		else if(sign == 1) {
			cout << minimum;
		}
	}
}