#include <iostream>

using namespace std;

int N; //접시의 수
int d; //초밥의 가짓수
int k; //연속하여 먹는 접시의 수
int c; //쿠폰번호(초밥 종류 1개)

int table[30000]; //[접시 번호] = 초밥 번호

int main() {
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}

	int maxcnt = 0;
	for (int i = 0; i < N; i++) { //i: 시작하는 접시 번호
		int dat[3001] = {}; //[초밥 번호] = 먹은 것:1, 안 먹은 것:0
		dat[c] = 1;
		int cnt = 1;

		for (int j = 0; j < k; j++) {
			int susi = table[(i + j) % N];
			if (dat[susi] == 1) continue;

			cnt++;
			dat[susi] = 1;
		}

		maxcnt = max(maxcnt, cnt);
	}

	cout << maxcnt;
}