#include <iostream>
using namespace std;
int tower[100][100];
int rottower[100][100];
int n, m;
int visited[3][6];
int maxi = -2134567890;
void func(int level) {

	if (level == n) {

		for (int i = 0; i < m; i++) {
			int colused[201] = { 0, };
			for (int j = 0; j < n; j++) {
				if (colused[rottower[j][i]+100] == 1)return;
				colused[rottower[j][i]+100] = 1;
				
			}	
		}
		
		int mul = 1;
		for (int i = 0; i < m; i++) {
			int colsum = 0;
			for (int j = 0; j < n; j++) {
				
				colsum += rottower[j][i];
			}
			mul *= colsum;
		}
		if (maxi < mul) maxi = mul;
		return;
	}

		
	for (int i = 1; i <= m; i++) { //층별 회전하는 수
		if (visited[level][i] == 1)continue;


		for (int j = 0; j < m; j++) {

			rottower[level][(j+i)%m] = tower[level][j];

		}

		visited[level][i] = 1;
		func(level + 1);
		visited[level][i] = 0;
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tower[i][j];
		}
	}


	func(0);

	cout << maxi;
}