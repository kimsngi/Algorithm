#include <iostream>
#include <string.h>

using namespace std;

int N; // ������� ��
int target[4]; // �ּ� �ܹ���, ����, ź��ȭ��, ��Ÿ��
int table[15][5]; // {�ܹ���, ����, ź��ȭ��, ��Ÿ��, ����}

int visited[15];
int minCost =1234567890;
int minVisit[15];

void dfs(int lev) {
	if (lev == N) {
		int sum[5] = { 0 };
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				for (int j = 0; j < 5; j++) {
					sum[j] += table[i][j];
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (sum[i] < target[i]) return;
		}
		if (sum[4] >= minCost) return;

		minCost = sum[4];
		for (int i = 0; i < N; i++) {
			minVisit[i] = visited[i];
		}
		return;
	}

	visited[lev] = 0;
	dfs(lev + 1);

	visited[lev] = 1;
	dfs(lev + 1);

	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < 4; i++) {
		cin >> target[i]; // ��ǥ ����� ��ġ
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> table[i][j]; //���̺� �Է�
		}
	}

	dfs(0);

	if (minCost == 1234567890) cout << -1;
	else {
		cout << minCost << "\n";
		for (int i = 0; i < N; i++) {
			if (minVisit[i]) cout << i + 1 << " ";
		}
	}
}