#include <iostream>
#include <queue>
using namespace std;
struct Heap {
	int from;
	int to;
	int len;
};

bool operator<(Heap a, Heap b) {

	if (a.len < b.len) return true;
	if (a.len > b.len) return false;

	return false;
}
int arr[26][26];
priority_queue<Heap> EE;

int main() {
	int n;
	cin >> n;
	Heap edge[900];

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> arr[i][j];
			edge[k].from = i;
			edge[k].to = j;
			edge[k].len = arr[i][j];
			EE.push(edge[k]);
			k++;

		}
	}
	char st[26];
	for (int i = 0; i < 26; i++) {
		st[i] = i + 'A';
	}

	for (int i = 0; i < 3;i++) {
		Heap out = EE.top();
		EE.pop();

		cout << st[out.from] << "-" << st[out.to] << " " << out.len << "\n";

	}

}