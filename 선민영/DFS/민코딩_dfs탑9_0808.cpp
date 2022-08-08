#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
int cnt = 0;
int sum = 0;
int visited[100000];
int n, e, student;
vector<int>v[100001];
void dfs(int now) //주어진 학생보다 낮은 점수 받은 학생 수 찾기
{
	for (int i = 0; i <v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next] == 1)continue;
		visited[next] = 1;
		cnt++;
		dfs(next);
	}
}
void dfsfront(int now) //주어진 학생보다 높은 점수 받은 학생 수 찾기
 {
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < v[i].size(); k++) {
			if (v[i][k] == now) {
				sum++;
			}
		}
	}
}

int main() {
	cin >> n >> e >> student;
	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> from>>to;
		v[from].push_back(to);
	}
	dfs(student);
	dfsfront(student);
	cout << sum + 1<<"\n"; //높은 학생 수 다음 등수가 가장 높은 등수
	cout << n - cnt; //주어진 학생 수에서 낮은 점수 받은 학생 수 뺀 것이 가장 낮은 등수
}
