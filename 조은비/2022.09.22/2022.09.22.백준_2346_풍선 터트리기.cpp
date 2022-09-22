#include <iostream>
#include <deque>

using namespace std;

int N;
int arr[1000];
deque <int> dq;

int main() {
	cin >> N;
	int NN = N;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		dq.push_back(n);
	}

	int num = 0;

	for (int n = 0; n < N; n++) {

		if (num > 0) {
			for (int j = 1; j < num; j++) {
				int temp = dq.front(); dq.pop_front();
				dq.push_back(temp);
			}
		}
		else {
			num = abs(num);
			for (int j = 0; j < num; j++) {
				int temp = dq.back(); dq.pop_back();
				dq.push_front(temp);
			}
		}

		int i = dq.front(); dq.pop_front(); // i: 터트리는 풍선 번호
		cout << i + 1 << " ";
		num = arr[i];
	}
}