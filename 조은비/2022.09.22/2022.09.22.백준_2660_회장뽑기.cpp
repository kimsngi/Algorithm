#include <iostream>
#include <queue>

using namespace std;

struct edge { int m; int s; }; //m: ȸ��, s:����� ����(����)

bool operator < (edge A, edge B) {
	return A.s > B.s;
}

int N; //ȸ�� ��
vector <int> mem[51]; //mem[ȸ��] = {ģ��1, ģ��2, ...} ; ģ�� ���� ���� ����
int arr[51]; //arr[ȸ��] = ���� ; ���� ���� �迭

int dijkstra(int x) {
	int score[51];
	for (int i = 1; i <= N; i++) {
		score[i] = N;
	}
	score[x] = 0;

	priority_queue <edge> pq;

	for (int i = 0; i < mem[x].size(); i++) { // ���� ȸ���� ģ�� ���� pq�� �Է�
		pq.push({ mem[x][i], 1 });
	}

	while (!pq.empty()) {
		edge temp = pq.top(); pq.pop();

		if (temp.s < score[temp.m]) {
			score[temp.m] = temp.s;

			for (int i = 0; i < mem[temp.m].size(); i++) { //ģ���� ģ�� ���� pq�� �Է�
				pq.push({ mem[temp.m][i], temp.s + 1 });
			}
		}
	}

	int maxScore = 0;
	for (int i = 1; i <= N; i++) {
		maxScore = max(maxScore, score[i]);
	}

	return maxScore;
}

int main() {
	cin >> N;

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1) break;

		mem[a].push_back(b);
		mem[b].push_back(a);
	}

	int minScore = N;
	for (int i = 1; i <= N; i++) {
		arr[i] = dijkstra(i);
		minScore = min(minScore, arr[i]);
	}

	vector <int> candi;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == minScore) {
			candi.push_back(i);
		}
	}

	cout << minScore << " " << candi.size() << "\n";
	for (int i = 0; i < candi.size(); i++) {
		cout << candi[i] << " ";
	}
}