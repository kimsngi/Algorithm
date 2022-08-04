//2022년 08월 04일 알고리즘 스터디 문제1

#include <iostream>

using namespace std;

int DAT[200];

int main() {
	char ch[3][100];
	for (int i = 0; i < 3; i++) {
		cin >> ch[i];
	}

	int flag = 0;
	for (int i = 0; i < 3; i++) {
		int j = 0;
		while (ch[i][j] != '\0') {
			int a = ch[i][j];
			if (DAT[a] != 0) {
				flag = 1;
				break;
			}
			DAT[a]++;
			j++;
		}
	}

	if (flag) cout << "No";
	else cout << "Perfect";
}