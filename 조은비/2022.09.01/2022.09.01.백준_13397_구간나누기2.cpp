//맞았습니다!! / 2040KB / 0ms
#include <iostream>

using namespace std;

int arr[5000]; //
int N; //수의 개수
int M; //구간의 수

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int minScore;
	int left = 0; int right = 10000;
	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		int i = 0;
		while (i < N) {
			cnt++;

			int minV = 10000; int maxV = 0;
			while (i < N) {
				minV = min(minV, arr[i]);
				maxV = max(maxV, arr[i]);
				if (maxV - minV > mid) break;
				i++;
			}
		}

		if (cnt <= M) {
			minScore = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << minScore;
}