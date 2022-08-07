#include <iostream>
#include <vector>

using namespace std;

vector <int> high_low[100001]; //등수 힌트 정보
vector <int> low_high[100001];
int visited[100001] = { 0, };

int lower = 0;
void dfs1(int X) { //학생 X보다 낮은 등수의 학생 찾기
	for (int i = 0; i < high_low[X].size(); i++) {
		int next = high_low[X][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		lower++;
		dfs1(next);
	}
}

int heigher = 0;
void dfs2(int X) { //학생 X보다 높은 등수의 학생 찾기
	for (int i = 0; i < low_high[X].size(); i++) {
		int next = low_high[X][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		heigher++;
		dfs2(next);
	}
}

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		high_low[a].push_back(b); //a행에 a보다 낮은 등수 b 푸시
		low_high[b].push_back(a); //b행에 b보다 높은 등수 a 푸시
	}

	dfs1(X);
	dfs2(X);

	int U = 1 + heigher; //가능한 가장 높은 등수
	int V = N - lower; //가능한 가장 낮은 등수

	cout << U << "\n" << V;
}