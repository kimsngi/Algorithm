#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int rank[100001];
int visited[100001];

// N : 학생 수, M : 질문의 개수, X : 등수를 알아낼 학생 번호 
int N, M, X;

// 인접 리스트로 풀어보기??
vector<int> v[100001];
vector<int> v2[100001];

// 1. 나보다 확실하게 위에 있는 등수의 사람들 수 찾기
// 2. 나보다 확실하게 아래에 있는 등수의 사람들 수 찾기

// 나의 가능한 최고 등수 = 나보다 확실하게 있는 사람들의 수 + 1
// 나의 가능한 최저 등수 = 총 인원 수 - 나보다 확실하게 아래에 있는 사람들의 수

// cnt -> 나보다 위에 있는 사람들 수, cnt_reverse -> 나보다 아래에 있는 사람들 수
int cnt = 0, cnt_reverse = 0;

// 자신보다 낮은 등수를 찾는다
void dfs(int student) {
    // 기저 조건
    if (visited[student]) return;

    // dfs 재귀
    visited[student] = 1;
    cnt++;

    for (int i = 0; i < v[student].size(); i++) {
        int next = v[student][i];
        dfs(next);
    }

}

// 자신보다 높은 등수를 찾는다
void dfs_reverse(int student) {
    // 기저 조건
    if (visited[student]) return;

    // dfs 재귀
    visited[student] = 1;
    cnt_reverse++;

    for (int i = 0; i < v2[student].size(); i++) {
        int next = v2[student][i];
        dfs_reverse(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v2[to].push_back(from);
    }
    dfs(X);

    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }

    dfs_reverse(X);
    
    // 두 정수 U,V 출력 - 가장 높은 등수 U 가장 낮은 등수 V
    int U = cnt_reverse - 1 + 1;
    int V = N - (cnt - 1);

    cout << U << "\n" << V;

}