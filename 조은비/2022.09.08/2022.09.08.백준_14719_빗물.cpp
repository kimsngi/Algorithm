//맞았습니다!! 2028KB 0ms
#include <iostream>

using namespace std;

int arr[500]; // 블록높이
int L_height[500]; // 블록의 왼쪽으로 가장 높은 블록의 높이
int R_height[500]; // 블록의 오른쪽으로 가장 높은 블록의 높이

int main() {
	int H; //세계의 세로 길이
	int W; //세계의 가로 길이

	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	int left_value = 0;
	for (int i = 0; i < W; i++) {
		left_value = max(left_value, arr[i]);
		L_height[i] = left_value;
	}

	int right_value = 0;
	for (int i = W - 1; i >= 0; i--) {
		right_value = max(right_value, arr[i]);
		R_height[i] = right_value;
	}

	int sum = 0;
	for (int i = 0; i < W; i++) {
		int a = min(L_height[i], R_height[i]) - arr[i];
		if (a > 0) sum += a;
	}

	cout << sum;
}