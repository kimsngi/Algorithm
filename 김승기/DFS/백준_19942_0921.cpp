#include <iostream>
#include <vector>
using namespace std;
int fdata[16][5];
int visited[16];
int n;
int mp, mf, ms, mv;
int ans =10000;
int minans = 10000;
int sm[5];
vector<int> path;
vector<int> anspath;
void dfs(int nowlevel,int now) {

	if (sm[0] >= mp && sm[1] >= mf && sm[2] >= ms && sm[3] >= mv) {

		ans = sm[4];
		if (minans > ans) {
			anspath.clear();
			for (int i = 0; i < path.size(); i++) {

				anspath.push_back(path[i]);
			}
			minans = ans;
		}
		return;

	}

	for (int i = now +1; i <= n; i++) {
		if (visited[i] == 1)continue;
		
		for (int j = 0; j < 5; j++) {
			sm[j] += fdata[i][j];

		}
		

		visited[i] = 1;
		path.push_back(i);

		dfs(nowlevel + 1 ,i);

		path.pop_back();
		visited[i] = 0;

		for (int j = 0; j < 5; j++) {
			sm[j] -= fdata[i][j];

		}
	}
	
}


int main() {
	
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	int full[6] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> fdata[i][j];
			full[j] += fdata[i][j];
		}
	}
	
	
	if (full[0] < mp || full[1] < mf || full[2] < ms || full[3] < mv) {
		cout << -1;
		exit(0);
	}

	for (int i = 1; i <= n; i++) {
		
		dfs(0,0);

	}
	
	cout << minans<<"\n";
	for (int i = 0; i < anspath.size(); i++) {
		cout << anspath[i] << " ";
	}
}