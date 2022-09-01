#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

// m개 이하의 구간으로 나누기
int n, m;
int arr[5001];

// mid값 기준으로 m개 이하의 구간 나눌 수 있는 경우
int makeArr(int val) {

    int cnt = 1;
    int temp_max = -2134567890;
    int temp_min = 2134567890;

    for (int i = 0; i < n; i++) {

        temp_max = max(temp_max, arr[i]);
        temp_min = min(temp_min, arr[i]);

        // 현재부터 i까지 구간 점수가 val보다 작거나 같아야 함
        // 구간에 포함시키기
        if (temp_max - temp_min <= val) {
            continue;
        }
        // 새로운 구간 만들기
        else {
            // 현재 index에서 다시 구간 새로 시작
            temp_max = arr[i];
            temp_min = arr[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int temp_max = -2134567890;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp_max = max(arr[i], temp_max);
    }

    int left = 0;
    int right = temp_max;
    int ans = 0;

    while (left <= right) {
        // mid : 찾고자 하는 정답
        int mid = (left + right) / 2;

        if (makeArr(mid) <= m) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }
    cout << ans;
}