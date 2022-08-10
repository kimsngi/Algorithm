#include <iostream>
#include <queue>
using namespace std;
struct stud {
	int h;
	int num;
};
bool operator<(stud a, stud b) {
	if (a.h < b.h) return true;
	if (a.h > b.h) return false;
	if (a.num < b.num) return false;
	if (a.num > b.num) return true;

	return false;
}
int dat[2][1000001]; //입력 받는 용도
int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		priority_queue<stud> pq;
		for (int j = 0; j < n; j++) {
			
			cin >> dat[0][j];
		}
		for (int j = 0; j < n; j++) {
			cin >> dat[1][j];
		}
		for (int j = 0; j < n; j++) {

			pq.push({ dat[0][j],dat[1][j] });
			
		}

		int flag = 0;
		int cnt = 1;
		while (!pq.empty()) {
			stud student = pq.top();
			if (student.num != cnt) {
				flag = 1;
				cout << "NO";
				break;
			}
			cnt++;
			pq.pop();
		}
		if (flag == 0)cout << "YES";
		cout << "\n";
	}

}