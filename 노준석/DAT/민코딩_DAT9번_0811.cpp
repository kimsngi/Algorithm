#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

int n;
int order_num;

int id_dat[100001];
int exit_dat[100001];
string name_dat[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> order_num;
        // 회원 가입 관리
        if (order_num == 1) {
            int id;
            string name;
            cin >> id >> name;

            // 중복되는 사번이 있는 경우
            if (id_dat[id]) {
                cout << id << " ERROR" << "\n";
            }
            else {
                cout << id << " OK" << "\n";
                id_dat[id] = 1;
                name_dat[id] = name;
            }
        }

        // 출,입 관리
        if (order_num == 2) {
            int id;
            cin >> id;
            // 입력한 사번의 사람이 없는 경우
            if (!id_dat[id]) {
                cout << id << " ERROR" << "\n";
                continue;
            }
            // 나가있던 상태라면
            if (!exit_dat[id]) {
                cout << id << " " << name_dat[id] << " ENTER" << "\n";
                exit_dat[id] = 1;
            }
            // 들어와있던 상태라면
            else {
                cout << id << " " << name_dat[id] << " EXIT" << "\n";
                exit_dat[id] = 0;
            }
        }
    }
    
}