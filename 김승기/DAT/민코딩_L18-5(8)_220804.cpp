#include <iostream>
#include <string>
using namespace std;
int main() {

	int dat[26] = { 0, };
	string input[3];
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}

	for (int j = 0; j < 3; j++) {

		for (int i = 0; i < input[j].size(); i++) {
		
			dat[input[j][i] - 'A']++;

		}

	}
	int flag = 0;
	for (int i = 0; i < 26; i++) {

		if (dat[i] > 1) {
			flag = 1;
		}
		
	}

	if (flag == 1) {
		cout << "No";
	}
	else if(flag==0) {
		cout << "Perfect";
	}

}