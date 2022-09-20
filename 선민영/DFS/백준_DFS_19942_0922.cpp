#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
int n;
struct Node {
	int protein, fat, cab, vit, price;
};
vector<Node>arr;
int mp, mf, ms, mv;
int psum, fsum, csum, vsum;
int cnt;
int mini = 2134567890;
vector<int>path;
priority_queue<int, vector<int>, greater<int>>final;

void dfs(int i) {
	if (psum >= mp && fsum >= mf && csum >= ms && vsum >= mv) {
		if (mini > cnt) {
			mini = cnt;
			while (!final.empty()) {
				final.pop();
			}
			for (int i = 0; i < path.size(); i++) {
				final.push(path[i]);
			}
		}
		return;
	}
	for (int j = i + 1; j < n; j++) {
		path.push_back(j);
		cnt+=arr[j].price;
		psum += arr[j].protein;
		fsum += arr[j].fat;
		csum += arr[j].cab;
		vsum += arr[j].vit;
		dfs(j);
		cnt -= arr[j].price;
		psum -= arr[j].protein;
		fsum -= arr[j].fat;
		csum -= arr[j].cab;
		vsum -= arr[j].vit;
		path.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		int protein, fat, cab, vit, price;
		cin >> protein >> fat >> cab >> vit >> price;
		arr.push_back({ protein, fat, cab, vit, price });
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		path.push_back(i);
		cnt += arr[i].price;
		psum += arr[i].protein;
		fsum += arr[i].fat;
		csum += arr[i].cab;
		vsum += arr[i].vit;
		dfs(i);
		path.pop_back();
		psum -= arr[i].protein;
		fsum -= arr[i].fat;
		csum -= arr[i].cab;
		vsum -= arr[i].vit;
	}
	if (mini == 2134567890)cout << -1;
	else cout << mini << "\n";
	while (!final.empty()) {
		cout << final.top()+1<<" ";
		final.pop();
	}
}