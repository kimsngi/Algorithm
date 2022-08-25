#include <iostream>

using namespace std;

int Ms; //초기 투자액
int Ma; //월별 투자금액
int N; //종목 수
int L; //데이터 기간
int table[15][16]; //[n][l] = l개월 차 n의 가격

int dat[15]; //[n] = 매수 개수
int maxmoney;
void func(int money, int n, int l) { //현재 가진 돈, 현재 종목, 현재 기간
	if (n == N) {
		int summoney = money;
		for (int i = 0; i < N; i++) {
			summoney += table[i][l+1] * dat[i];
		}

		maxmoney = max(maxmoney, summoney);
		return;
	}

	int i = 0;
	while (1) {
		int change = money - table[n][l] * i;
		if (change < 0) return;

		dat[n] = i;
		func(change, n + 1, l);

		i++;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {

		//데이터 입력
		cin >> Ms >> Ma >> N >> L;

		for (int n = 0; n < N; n++) {
			for (int l = 0; l <= L; l++) {
				cin >> table[n][l];
			}
		}

		int money = Ms;
		for (int i = 0; i < L; i++) {
			maxmoney = 0;

			func(money, 0, i);

			money = maxmoney;
			money += Ma;
		}

		cout << "#" << t << " ";
		cout << money - Ms - (Ma * L) << "\n";
	}
}