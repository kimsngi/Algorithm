#include <iostream>
#include <queue>
using namespace std; \
int sc[1000][2];

priority_queue<int> q;
int main() {
	int n;
	cin >> n;
	int k = 0;
	int save[1000];
	q.push( 500);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> sc[i][j];
			q.push(sc[i][j]);
	
		}
		int x = 0;
		int out;
		while (q.size() > i + 1) {

			out = q.top();
			q.pop();
			save[x] = out;
			x++;

		}
		cout << out << "\n";
		for (int j = 0; j <i+2 ; j++) {
			
			q.push(save[j]);

		}

	}
	
	


}