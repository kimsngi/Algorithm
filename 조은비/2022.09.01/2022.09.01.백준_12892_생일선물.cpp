//맞았습니다!! / 3584KB / 124ms
#include <iostream>
#include <algorithm>

using namespace std;

int N; //친구의 수
int D; //최소 가격차
long long maxSumV;

struct node { int P; long long V; };
node arr[100000];

bool operator < (node A, node B) {
	return A.P < B.P;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].P >> arr[i].V;
	}

	sort(arr, arr + N);

	long long sumV = 0;
	int i = 0; int j = 0;
	while (j < N) {
		if (arr[j].P < arr[i].P + D) {
			sumV += arr[j++].V;
			// cout << "i: " << i << " j: " << j << " sum: " << sumV << "\n";
			maxSumV = max(maxSumV, sumV);
		}
		else {
			sumV -= arr[i++].V;
		}
	}

	cout << maxSumV;
}