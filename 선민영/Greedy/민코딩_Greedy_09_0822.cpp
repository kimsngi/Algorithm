#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int arr[26] = { 0, };
int dat[26] = { 0, };
int final[10] = { 0, };
string stri[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stri[i] = str;
		int p = 0;
		for (int k = str.size()-1; k >=0; k--){
			arr[(int)(str[p] - 'A')] += pow(10,  k);
			p++;
		}
	}
	int maxnum;
	int amount = 9;
	while (1) {
		int maxval = 0;
		for (int i = 0; i < 26; i++) {
			if (arr[i] > maxval) {
				maxval = arr[i];
				maxnum = i;
			}
		}
		if (maxval == 0)break;
		arr[maxnum] = 0;
		dat[maxnum] = amount;
		amount--;
	}
	for (int i = 0; i < n; i++) {
		int q = stri[i].size() - 1;
		for (int k = 0; k < stri[i].size(); k++) {
			final[i] += dat[(int)(stri[i][k]-'A')] * pow(10, q);
			q--;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += final[i];
	}
	cout << sum;
}
	
