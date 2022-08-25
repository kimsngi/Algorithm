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

int n, m;
long long arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    // 2 1
    // 1 1
    while (cnt != m) {
        long long temp_sum = arr[0] + arr[1]; // 가장 작은 수 두개 더함
        arr[0] = temp_sum;
        arr[1] = temp_sum;

        sort(arr, arr + n);
        cnt++;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << sum;
}