#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int n, d, k, c;
int sushi[30001];
int dat[3001]; // 먹은 초밥 저장 dat

bool checkOne() {
    for (int i = 0; i < d+1; i++) {
        // 2개 이상 먹은 종류가 있다면 안된다
        if (dat[i] >= 2) {
            return false;
        }
    }
    return true;
}

int func() {
    int cnt = 0;
    for (int i = 0; i < d + 1; i++) {
        if (dat[i] >= 1) cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // k개 만큼 먹을 수 있음
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    int max_result = -2134567890;
    // sliding window
    // 7,9,7,30,2,7,9,25

    int left = 0;
    int right = k - 1;

    // 공통 구간 초밥 넣어놓기
    for (int i = left; i < right; i++) {
        dat[sushi[i]] += 1;
    }

    // left가 마지막 까지 올 때 까지 반복
    while (left < n) {

        right = right % n;

        // 구간 완성 => 초밥 k개 먹은 상태
        dat[sushi[right]] += 1;

        // 먹은 초밥 종류의 개수 = dat에서 1개 이상인 개수
        int cnt = func();

        // 만약 쿠폰 사용해서, 새로운 초밥 먹을 수 있으면 개수 1개 증가
        if (dat[c] == 0) {
            cnt += 1;
        }
        max_result = max(cnt, max_result);

        dat[sushi[left]] -= 1;
        left++;
        right++;
    }
    cout << max_result;
}