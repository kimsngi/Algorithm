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

struct Node {
    int idx; // 종목 번호
    int diff; // 다음 달과의 차이값
    int price;
};

struct Node2 {
    int idx;
    int price;
};

// 다음 달과의 차이값이 큰 거일수록 앞으로 꺼냄
// 만약 차이값이 같다면, 가격이 싼 것일수록 앞으로 꺼냄
bool operator<(Node a, Node b) {
    if (a.diff > b.diff) return false;
    if (a.diff < b.diff) return true;

    if (a.price < b.price) return false;
    if (a.price > b.price) return true;
    return false;
}

int T;
// ms - 첫 시드액, ma - 월별 투자금액
int ms, ma;
// n - 종목 수, l - 과거 데이터 기간
int n, l;

int board[16][16];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {

        cin >> ms >> ma;
        cin >> n >> l;
        int origin_money = ms + ma * l;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= l; j++) {
                cin >> board[i][j];
            }
        }
        
        // 1. n개의 종목 모두 다음 달 거랑 비교해서 가격 차가 제일 큰 것 찾기
        // 1-1. 만약 제일 큰 가격 차가 0 이하의 숫자 => 저축
        // 2. 가장 차가 큰 것 최대 가격까지 매수
        // 3. 다음달에 매수한 것 해당 달 가격으로 매도
        // 4. 반복

        queue<Node2> q;
        priority_queue<Node> pq;

        // 0개월~l개월까지 반복
        for (int a = 0; a < l; a++) {
            if (a >= 1) ms += ma; // 매월 추가 금액

            int max_price = -2134567890;
            int max_price_idx;

            // 1. n개의 종목 모두 다음 달 거랑 비교해서 양수면 넣는다
            for (int b = 0; b < n; b++) {
                int temp_price = board[b][a + 1] - board[b][a];
                if (temp_price > 0) {
                    pq.push({ b,temp_price,board[b][a]});
                }
                if (temp_price > max_price) {
                    max_price = temp_price;
                    max_price_idx = b;
                }
            }

            // 1-1. 만약 제일 큰 가격 차가 0 이하의 숫자 => 저축
            if (max_price <= 0) {
                continue;
            }

            // 2. 가장 차가 큰 것 최대 가격까지 매수
            int mcnt = 1;
            int temp_ms = ms;
            while (!pq.empty()) {
                Node now = pq.top();
                if (temp_ms > board[now.idx][a]) {
                    temp_ms -= board[now.idx][a];
                }
                else {
                    pq.pop();
                    continue;
                }
                q.push({ now.idx,board[now.idx][a] });
                ms -= board[now.idx][a];
            }

            // 3. 다음달에 매수한 것 해당 달 가격으로 매도
            if (!q.empty()) {
                while (!q.empty()) {
                    Node2 now = q.front();
                    ms += board[now.idx][a + 1];
                    q.pop();
                }
            }

        }

        int result = ms - origin_money + ma;
        cout <<"#"<<t<<" "<< result << "\n";
    }
}