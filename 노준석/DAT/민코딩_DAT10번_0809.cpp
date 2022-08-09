#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int T, N;
int height[1000001];
int request[1000001];
int temp[1000001] = { 0, };

bool cmp(int a, int b) {
    if (a > b) return true;
    if (a < b) return false;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            temp[j] = 0;
        }
        for (int j = 0; j < N; j++) {
            cin >> height[j];
            temp[j] = height[j];
        }
        for (int j = 0; j < N; j++) {
            // request = 2 3 5 1 4
            cin >> request[j];
        }
        // 인 :  1   2   3   4   5
        // 키 : 232 202 195 195 191
        sort(height, height + N,cmp);

        bool flag = true;

        // 만약 순서 일치하지 않으면 flag false
        for (int j = 0; j < N; j++) {
            if (height[request[j]-1] != temp[j]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

}