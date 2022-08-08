#include <iostream>
#include <string>
#include <vector>
using namespace std;
string magic;
string dev;
string ang;
int cnt = 0;
int ans = 0;
int visited[401];
vector<int> path;
void dfs(int flag,int now) {
	if (flag == 1) {

		if (cnt == magic.size()) {
			
			ans++;
			return;
		}


		for (int next = now+1; next < dev.size(); next++) {

		
			if (dev[next] != magic[cnt])continue;
			
			if (visited[next] == 1)continue;

			path.push_back(next);
			visited[next] = 1;
			cnt++;
			dfs(-1*flag,next);
			visited[next] = 0;
			path.pop_back();
			cnt--;

		}


	}
	else if (flag == -1) {
		if (cnt == magic.size()) {
			
			ans++;
			return;
		}


		for (int next = now+1; next < ang.size(); next++) {


			if (ang[next] != magic[cnt])continue;
			
			if (visited[next] == 1)continue;

			path.push_back(next);
			visited[next] = 1;
			cnt++;
			dfs(-1 * flag, next);
			visited[next] = 0;
			path.pop_back();
			cnt--;

		}
	}


}


int main() {
	cin >> magic;
	cin >> dev >> ang;
	
	dfs(1, -1);
	
	dfs(-1, -1);
	

	cout<<ans;

}