#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int dat[26]; //dat['A'] = 'A'의 합

void func(string str) { //문장 분해 ('A' * 100, 'B' * 10, 'C' * 1, ...)
	int len = str.length();
	for (int i = 0; i < len; i++) {
		dat[str[i]-'A'] += pow(10, len - i - 1);
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		func(str);
	}



	sort(dat, dat + 26, greater<>());

	int sum = 0; int j = 9;
	for (int i = 0; i < 10; i++) {
		sum += dat[i] * j;
		j--;
	}

	cout << sum;
}