#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MY_MAX -2134567890;
#define MY_MIN 2134567890;

string order;
string devil, angel;

vector<char> path;
int visited_devil[128];
int visited_angel[128];

//false일 때 악마의 돌다리, true일 때 천사의 돌다리
bool flag = false;
int cnt = 0;

void dfs(int level, bool flag, int temp_cnt) {
    // 기저 조건 : 두루마리 다 읽었을 경우
    if (level == order.size()) {
        cnt++;
        /*for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";*/
        return;
    }

    // dfs 재귀
    if (!flag) {
        for (int i = temp_cnt; i < devil.size(); i++) {
            char next = devil[i];
            //if (visited_devil[next - 'A']) continue;

            if (next == order[level]) {
                path.push_back(next);
                visited_devil[next - 'A'] = 1;
                int test = i + 1;

                dfs(level + 1, !flag, test);

                path.pop_back();
                visited_devil[next - 'A'] = 0;
            }
        }
    }

    if (flag) {
        for (int i = temp_cnt; i < angel.size(); i++) {
            char next = angel[i];
            //if (visited_angel[next - 'A']) continue;

            if (next == order[level]) {
                path.push_back(next);
                visited_angel[next - 'A'] = 1;
                int test = i + 1;

                dfs(level + 1, !flag, test);

                path.pop_back();
                visited_angel[next - 'A'] = 0;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> order;
    cin >> devil >> angel;
    
    dfs(0,false,0);
    for (int i = 0; i < 128; i++) {
        visited_angel[i] = 0;
        visited_devil[i] = 0;
    }
    
    dfs(0, true, 0);

    cout << cnt;
}