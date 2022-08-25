#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

struct info {
	int buyid;
	int buycnt;
	};
struct iteminfo {
	int diff;
	double diffrat;
	int itemid;
};

int stData[15][16];
int diff[16];
int selldiff[15];
double rat[15];

bool operator<(iteminfo a, iteminfo b) {

	if (a.diffrat < b.diffrat) return true;
	if (a.diffrat > b.diffrat) return false;

	return false;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		memset(stData, 0, sizeof(stData));
		memset(diff, 0, sizeof(diff));
		memset(selldiff, 0, sizeof(selldiff));
		vector<info> buymemo[16];
		priority_queue<iteminfo> item[16];

		int Ms, Ma, N, L;
		cin >> Ms >> Ma >> N >> L;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= L; j++) {
				cin >> stData[i][j];
			}
		}
		int curMoney = Ms;

		for (int time = 0; time <= L; time++) {

			if (time >= 1) {
				curMoney += Ma;
			}

			//매도
			int plus = 0;
			if (time >= 1) {

				for (int i = 0; i < buymemo[time - 1].size(); i++) {

					int nowid = buymemo[time - 1][i].buyid;  //매수 종목index
					int nowcnt = buymemo[time - 1][i].buycnt;//매수량
					selldiff[i] = stData[nowid][time]; // 매수 금액
					plus += selldiff[i] * nowcnt;

				}

				curMoney += plus;

			}

			if (time == L)continue; // L개월 차엔 매수 X;
			
			//매수
			for (int i = 0; i < N; i++) {
				
				if (stData[i][time] >= stData[i][time + 1])continue; 
				diff[i] = stData[i][time + 1] - stData[i][time]; // 1주당 이익
				rat[i] = (double)diff[i] / (double)stData[i][time]; // 1주당 현재 가격 대비 이익 비율
				item[time].push({ diff[i],rat[i],i});
				
			}

			if (item[time].size() > 0) {


				while (!item[time].empty()) {
					iteminfo now = item[time].top();
					int nowprice = stData[now.itemid][time];

					item[time].pop();

					if (curMoney < nowprice)continue;

					int buycnt = 0;
					buycnt = curMoney / nowprice;

					if (buycnt > 0) {

						curMoney -= (buycnt * nowprice);
						buymemo[time].push_back({ now.itemid,buycnt });
						
					}

				}

			}

		}
		int ans = 0;
		ans = curMoney - (Ms + (Ma * L));

		cout << "#"<<test_case <<" "<<ans << "\n";

	}
}