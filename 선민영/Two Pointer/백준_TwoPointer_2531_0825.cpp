#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;
int arr[60001];
int dat[3003];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	dat[c] = 1;
	int left = 0; 
	int right = k-1;
	for (int i = 0; i <= right; i++) {
		dat[arr[i]]++;
	}
	int cnt = 0; 
	for (int i = 1; i <= d; i++) {
		if (dat[i] != 0)cnt++;
	}
	int maxval = 0;
	if (cnt > maxval)maxval = cnt;
	while (left < n) {
		
		right++;
		dat[arr[left]]--;
		if (dat[arr[left]] == 0)cnt--;
		if (dat[arr[right]] == 0)cnt++;
		dat[arr[right]]++;
		if (cnt > maxval)maxval = cnt;
		left++;
	}
	cout << maxval;
}