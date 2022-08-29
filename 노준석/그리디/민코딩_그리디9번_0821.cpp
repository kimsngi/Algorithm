#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Word {
    char word;
    int value;
};

int n;
string str[11];
int dat[30];
Word words[30];

bool cmp(Word a, Word b) {
    if (a.value < b.value) return false;
    if (a.value > b.value) return true;

    if (a.word < b.word) return true;
    if (a.word > b.word) return false;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 우선순위 기준으로 숫자 부여하기(0~9)
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        int mul = 1;
        for (int j = str[i].size()-1; j > -1; j--) {
            // 단어의 우선순위 정하기
            int value = 1 * mul;

            // 각 단어별로 중요도 value가 저장된 구조체 배열
            words[str[i][j] - 'A'].word = str[i][j];
            words[str[i][j] - 'A'].value += value;

            mul *= 10;

        }
    }
    // 우선순위(value) 기준 정렬
    sort(words, words + 30, cmp);
    
    int start = 9;
    int idx = 0;
    int result = 0;
    while (words[idx].word != 0) {
        result += (words[idx].value * start);
        start--;
        idx++;
    }
    cout << result;
}