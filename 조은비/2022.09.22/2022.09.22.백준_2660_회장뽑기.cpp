#include <iostream>
#include <queue>

using namespace std;

struct edge { int m; int s; }; //m: 회원, s:가까운 정도(점수)

bool operator < (edge A, edge B) {
	return A.s > B.s;
}

int N; //회원 수
vector <int> mem[51]; //mem[회원] = {친구1, 친구2, ...} ; 친구 관계 저장 벡터
int arr[51]; //arr[회원] = 점수 ; 점수 저장 배열

int dijkstra(int x) {
	int score[51];
	for (int i = 1; i <= N; i++) {
		score[i] = N;
	}
	score[x] = 0;

	priority_queue <edge> pq;

	for (int i = 0; i < mem[x].size(); i++) { // 현재 회원의 친구 관계 pq에 입력
		pq.push({ mem[x][i], 1 });
	}

	while (!pq.empty()) {
		edge temp = pq.top(); pq.pop();

		if (temp.s < score[temp.m]) {
			score[temp.m] = temp.s;

			for (int i = 0; i < mem[temp.m].size(); i++) { //친구의 친구 관계 pq에 입력
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