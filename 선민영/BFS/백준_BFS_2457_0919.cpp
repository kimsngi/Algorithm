#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node {
	int bloomm, bloomd, diem, died;
};
struct node {
	int flower, cnt;
};
struct Edge {
	int flower, diem, died;
};
int n;
int maxval = 2134567890;
vector<Node>v;
bool cmp(Node a, Node b) {
	if (a.bloomm < b.bloomm)return true;
	if (a.bloomm > b.bloomm)return false;
	if (a.bloomd < b.bloomd)return true;
	if (a.bloomd > b.bloomd)return false;
	if (a.diem < b.diem)return true;
	if (a.diem > b.diem)return false;
	if (a.died < b.died)return true;
	if (a.died > b.died)return false;
	return false;
}
bool operator < (Edge a, Edge b) {
	if (a.diem < b.diem)return true;
	if (a.diem > b.diem)return false;
	if (a.died < b.died)return true;
	if (a.died > b.died)return false;
	if (a.flower < b.flower)return true;
	if (a.flower > b.flower)return false;
	return false;
}
queue<node>q;
priority_queue<Edge>qq;

void bfs(int start) {
	q.push({ start, 1 });
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (v[now.flower].diem == 12) {
			maxval = now.cnt;
			break;
		}
		if (now.flower + 1 == v.size())break;
		for (int i = now.flower+1; i < v.size(); i++) {
			if (v[i].bloomm > v[now.flower].diem)break;
			if (v[i].bloomm == v[now.flower].diem && v[i].bloomd > v[now.flower].died)continue;
			qq.push({i, v[i].diem, v[i].died});
		}
		if (qq.empty())break;
		q.push({ qq.top().flower, now.cnt+1 });
		while (!qq.empty()) {
			qq.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie();
	cout.tie();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int bloomm, bloomd, diem, died;
		cin >> bloomm>> bloomd>> diem>> died;
		if (bloomm == 12 || diem < 3)continue;
		v.push_back({ bloomm, bloomd, diem, died });
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<Edge>pq;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].bloomm > 3)break;
		if (v[i].bloomm == 3 && v[i].bloomd > 1)break;
		pq.push({i, v[i].diem, v[i].died});
	}
	if(!pq.empty()) bfs(pq.top().flower);
	if (maxval == 2134567890)cout << 0;
	else cout << maxval;
}

