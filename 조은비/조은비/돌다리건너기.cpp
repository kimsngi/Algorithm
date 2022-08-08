#include <iostream>

using namespace std;

int a = 0; //돌다리 스위치
int cnt = 0; //경로의 수
string magic; //마법 스펠링
string stone[2]; //돌다리

//dfs 함수
//level: 마법 스펠링 순서
//step: 돌다리 순서
void dfs(int level, int step) {
	if (level == magic.length()) { //기저조건 : 모든 스펠링을 밟았으면
		cnt++;                     //           경로의 수에 1을 더하고 리턴
		return;
	}

	for (int i = step; i < stone[a].length(); i++) { //돌다리를 step부터 1씩 증가
		if (magic[level] != stone[a][i]) continue;
		if (a == 0) a = 1; //돌다리 1/0 스위치
		else a = 0;
		dfs(level + 1, i + 1); //스펠링 찾으면 level+1(다음 마법 스펠링), i+1(현재 돌다리 순서의 다음부터)
		if (a == 0) a = 1; //리턴 후 다시 돌다리 스위치
		else a = 0;
	}
}

int main() {
	cin >> magic >> stone[0] >> stone[1];

	dfs(0, 0); //a가 0일 때 경로 수가 더해짐
	a = 1;
	dfs(0, 0); //a가 1일 때 경로 수도 더함

	cout << cnt;//경로 수 출력
}