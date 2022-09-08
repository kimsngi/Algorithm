#include <iostream>
using namespace std;
int blockcnt[500];
int main() {
	int H, W;
	cin >> H >> W;

	for (int i = 0; i < W; i++) {

		cin >> blockcnt[i];

	}

	int sum = 0;
	int maxi = 0;
	int diff = 0;
	int cnt = 0;
	int ans = 0;
	int flag = 0;

	for (int j = 1; j <= H; j++) {

		for (int i = 0; i < W; i++) {
			if (blockcnt[i] >= j) {
				flag = 1;
			}
			else if(blockcnt[i]<j && flag!=0) {
				flag = 2;
			}
			
			if (flag==2) {
				sum++;
			}
			if (flag==1) {
				ans += sum;
				sum = 0;
			}
		}
		flag = 0;
		sum = 0;
	}
	cout << ans;

}