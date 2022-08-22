#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //집의 개수
int C; //공유기의 개수

vector <int> v; //v[i] = 집의 좌표

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int min = 0; int max = 1000000000 / (C - 1);
	int value = 0;

	while (min <= max) {
		int mid = (min + max) / 2;

		int cnt = 1;
		for (int i = 0; i < N; i++) {

			for (int j = i + 1; j < N; j++) {
				if (v[j] - v[i] < mid) continue;

				cnt++;
				i = j - 1;
				break;
			}
		}

		if (cnt >= C) {
			value = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	cout << value;
}