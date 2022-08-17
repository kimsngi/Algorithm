#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int N, M;
int tower[3][5];
int rotateTower[3][5];

int colSum[100];

int clock_temp[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

// 배열 + (전체 크기 - 1), 회전 cnt만큼 하는 함수
void funcRotate(int arr[],int size, int cnt) {
    rotate(clock_temp, clock_temp + (size - cnt), clock_temp + size);
}

long long max_mul = -2134567890;

void dfs(int depth) {
    // 기저 조건
    if (depth == N) {
        for (int i = 0; i < M; i++) {
            colSum[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < depth; j++) {
                colSum[i] += rotateTower[j][i];
            }
        }
        long long result = 1;
        for (int i = 0; i < M; i++) {
            result *= colSum[i];
        }
        if (result > max_mul) {
            max_mul = result;
        }
        return;
    }

    // 재귀
    for (int i = 0; i < M; i++) {

        for (int j = 0; j < M; j++) {
            rotateTower[depth][j] = tower[depth][j];
        }
        
        funcRotate(rotateTower[depth], sizeof(rotateTower[depth]) / sizeof(int), i);
        
        dfs(depth + 1);

        funcRotate(rotateTower[depth], sizeof(rotateTower[depth]) / sizeof(int), -i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tower[i][j];
        }
    }
    
    dfs(0);
    
    cout << max_mul;
}