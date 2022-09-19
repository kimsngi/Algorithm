#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
using namespace std;
int arr[501];
int main() {
	ios_base::sync_with_stdio;
	cin.tie();
	cout.tie();
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int i = 0;
	while(i != w-1) {
		if (arr[i] > arr[i + 1]) {
			int k = 1;
			while (arr[i] > arr[i + k]) {
				if (i + k == w - 1)break;
				k++;
			}
			if (i + k == w - 1) {
				int j = w - 1;
				while (j != i) {
					if (arr[j] > arr[j - 1]) {
						int kk = 1;
						while (arr[j] > arr[j - kk]) {
							if (j - kk == i)break;
							kk++;
						}
						int final = min(arr[j], arr[j - kk]);
						for (int jj = j - kk+1; jj < j; jj++) {
							sum += final - arr[jj];
						}
						j -= kk;
					}
					else j--;
				}
			}
			if (i + k != w - 1) {
				int max = min(arr[i], arr[i + k]);
				for (int j = i + 1; j < i + k; j++) {
					sum += max - arr[j];
				}
			}
			i += k;
		}
		else i++;
	}
	cout << sum;
}
