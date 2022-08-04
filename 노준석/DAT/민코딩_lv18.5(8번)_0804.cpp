#include<iostream>
#include<queue>
#include <vector>
using namespace std;

int n;

int dat[128];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < s1.size(); i++) {
        dat[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++) {
        dat[s2[i]]++;
    }
    for (int i = 0; i < s3.size(); i++) {
        dat[s3[i]]++;
    }
    bool flag = true;
    for (int i = 0; i < 128; i++) {
        if (dat[i] > 1) {
            flag = false;
            break;
        }
    }
    // 같은 글자가 하나라도 있다
    if (!flag) cout << "No";
    else cout << "Perfect";

}