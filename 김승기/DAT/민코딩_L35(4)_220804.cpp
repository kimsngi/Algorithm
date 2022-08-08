#include <iostream>
#include <queue>
using namespace std;
struct edge {
	int from, to, cost;
};
bool operator<(edge a, edge b) {

	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	if (a.from < b.from) return false;
	if (a.from > b.from) return true;

	if (a.to < b.to) return false;
	if (a.to > b.to) return true;

	return false;
}



int arr[500][500];
edge Edg[250000];
priority_queue<edge> q;
int main() {

	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> arr[i][j];
			Edg[k].from = i;
			Edg[k].to = j;
			Edg[k].cost = arr[i][j];
			q.push(Edg[k]);
			k++;

		}
	}
	int cnt = 0;
	int flag = 0;
	while(!q.empty()){

		edge up = q.top();
		q.pop();
		if (up.cost == 0||up.cost==-1)continue;
		up.cost = 2 * up.cost;
		cnt++;
		if (cnt == 20) {
			cout << up.cost << "¸¸¿ø";
			break;
		}
		
		q.push(up);
	}


}