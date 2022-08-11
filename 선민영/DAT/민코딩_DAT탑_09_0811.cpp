#include <iostream>
#include <vector>
#include <string>
using namespace std;
int num[100001] = { 0, };
int num2[100001] = { 0, };
vector<string>v[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int casee;
		cin >> casee;
		if (casee == 1) {
			int numb; string name;
			cin >> numb >> name;
			v[numb].push_back(name);
			if (num[numb] == 0) {
				cout << numb << " OK" << "\n";
				num[numb] = 1;
			}
			else {
				cout << numb << " ERROR" << "\n";
			}

		}
		else {
			int numb2;
			cin >> numb2;
			if (num[numb2] == 1) {
				cout << numb2 << " " << v[numb2][0] <<" ENTER"<< "\n";
				num[numb2] = 2;
			}
			else if (num[numb2] == 2) {
				cout << numb2 << " " << v[numb2][0] <<" EXIT"<< "\n";
                num[numb2]=1;
			}
			else { cout << numb2 << " ERROR" << "\n"; }
		}
	}
}