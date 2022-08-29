#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int n, c;
int arr[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = -1;
    int left = 1;
    int right = arr[n - 1] - arr[0];

    while (left <= right) {
        // mid : 찾으려고 하는 값, 인접한 공유기 사이의 거리 값
        int mid = (left + right) / 2;

        int cnt = 1;
        int start = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] - start >= mid) {
                cnt++;
                start = arr[i];
            }
        }

        if (cnt >= c) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

}