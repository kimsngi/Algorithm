#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

long long arr[100001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int left = 0;
    int right = n - 1;

    long long sum = 0;
    long long min_sum = 2e18;

    // 값이 모두 음수면 가장 오른쪽 두개로 결정
    if (arr[n - 1] < 0) {
        cout << arr[n - 1] + arr[n - 2];
        return 0;
    }
    // 값이 모두 양수면, 가장 왼쪽 두개로 결정
    if (arr[0] >= 0) {
        cout << arr[0] + arr[1];
        return 0;
    }
    int result;
    // 투 포인터
    while (left < right) {
        sum = arr[left] + arr[right];

        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            result = sum;
        }
        // 값 비교
        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }

    }
    cout << result;
}