#include <iostream>
#include <algorithm>

using namespace std;

int sensor[10000];
int di[10000];

int main() {
	int N; //센서의 수
	int K; //집중국의 수
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> sensor[i];
	}

	sort(sensor, sensor + N);

	for (int i = 0; i < N - 1; i++) {
		di[i] = sensor[i + 1] - sensor[i];
	}

	sort(di, di + N - 1, greater<>());

	int ans = sensor[N - 1] - sensor[0];

	for (int i = 0; i < K - 1; i++) {
		ans -= di[i];
	}

	cout << ans;
}