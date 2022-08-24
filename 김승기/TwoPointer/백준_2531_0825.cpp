#include <iostream>
#include <string.h>
using namespace std;
int susi[30000];
int susinum[3001];
int main() {
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> susi[i];
	}

	int left = 0;
	int maxi = 0;
	

	while (left < n) {
		
		int cnt = 0;

		for (int i = left; i < left +k; i++) {

			if (susinum[susi[i%n]] == 0) {
				susinum[susi[i%n]] = 1;
				cnt++;
			}
			
		}
		if (susinum[c] == 0) {
			cnt++;
		}
		maxi = max(maxi, cnt);
		left++;

		memset(susinum, 0,sizeof(susinum));

	}

	cout << maxi;
}