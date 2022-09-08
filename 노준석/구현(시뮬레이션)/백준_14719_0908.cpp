#include <iostream>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int H, W;
int arr[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	
	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	int sum = 0;

	for (int cur = 1; cur < W - 1; cur++) {
		int left_max = -1;
		int right_max = -1;

		for (int left = cur - 1; left > -1; left--) {
			left_max = max(left_max, arr[left]);
		}
		for (int right = cur + 1; right < W; right++) {
			right_max = max(right_max, arr[right]);
		}
		
		int temp_max = min(left_max, right_max);
		if (arr[cur] < temp_max)
			sum += (temp_max - arr[cur]);
	}
	cout << sum;
	return 0;
}