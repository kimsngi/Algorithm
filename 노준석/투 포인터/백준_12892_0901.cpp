#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Node {
    int p;
    int v;
};

// 가격 기준 오름차순 정렬
bool cmp(Node a, Node b) {
    if (a.p < b.p) return true;
    if (a.p > b.p) return false;
    return false;
}

// n-친구의 수, d-미안함을 느끼게 되는 최소 가격차
int n, d;
// p-선물의 가격, v-만족도
Node arr[100001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].v;
    }

    sort(arr, arr + n, cmp);
    // 10 11 12 13
    // 20 30 40 10

    int left = 0;
    int right = 0;
    long long ans = 0;
    long long result_max = -1;

    while (left <= right) {
        // 만약 다음 탐색할 인덱스 가격 차이가 d 미만이면 탐색
        if (arr[right].p - arr[left].p < d) {
            ans += arr[right].v;
            right += 1;
        }
        // 만약 다음 탐색할 인덱스 가격 차이가 d 이상이면
        // left 이동 후 탐색 재시작
        else {
            ans -= arr[left].v;
            left += 1;
        }

        result_max = max(ans, result_max);
        if (right > n) break;
    }

    cout << result_max;
}