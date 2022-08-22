#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int n, k;
int arr[10001];
int gap_arr[10001];

bool cmp(int a, int b) {
    if (a < b) return false;
    if (a > b) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> k; // 구간의 개수

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    // 1,3,6,6,7,9
    // [1~3] , [6~9] => 2 + 3 = 5
    // 2 3 0 1 2
    // 3 2 2 1 0

    // 3 6 7 8 10 12 14 15 18 20
    // [3~3] , [6~8] , [10~15] , [18~18] , [20~20] => 0 + 2 + 5 + 0 + 0 = 7

    // 3 1 1 2 2 2 1 3 2
    // 3 3 2 2 2 2 1 1 1 

    // 집중국의 위치(좌표)를 특정하는 것이 아니었음..

    for (int i = 0; i < n - 1; i++) {
        gap_arr[i] = arr[i + 1] - arr[i];
    }

    sort(gap_arr, gap_arr + n - 1,cmp);

    int sum = 0;

    for (int i = k - 1; i < n - 1; i++) {
        sum += gap_arr[i];
    }
    cout << sum;
}