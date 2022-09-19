#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

priority_queue<int> pq;

int main() {
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N >> K;
		string input;
		cin >> input;

		int dat[6] = { 10,11,12,13,14,15 };
		int numarr[29] = { 0, };
		for (int i = 0; i < N; i++) {
			if (input[i] >= 'A' && input[i] <='Z') {
				input[i] = dat[input[i] - 'A'];
				numarr[i] = input[i];
			}
			else {
				numarr[i] = input[i] - '0';
			}

		}

		int numcnt = N / 4;
		int cnt = 0;
		int mul = 16;
		for (int i = 0; i < numcnt; i++) {
			
			for (cnt = 0; cnt < 4; cnt++) {
				int value = 0;
				for (int j = 0; j < numcnt; j++) {
					value += numarr[(i + cnt * numcnt + j)%N] * pow(16, numcnt - (j + 1));
					
				}

				pq.push(value);
	
			}

		}

		int kcnt = 0;
		int ans = 0;
		while (!pq.empty()) {
			int num = pq.top();
			pq.pop();
			if (pq.size() > 0) {

				if (num != pq.top()) {
					kcnt++;
				}
			}
			else {
				kcnt++;
			}

			if (K == kcnt) {
				ans = num;
			}
		}

		cout << "#" << test_case << " " << ans<<"\n";
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
