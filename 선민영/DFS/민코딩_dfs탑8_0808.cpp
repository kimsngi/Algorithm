#include <iostream>
#include <vector>
#include <string>
using namespace std;

string route;
string arr[2];
int t;
int q;
int nexts;
int sum = 0;
int nextd;
int length;

void dfs(int now, int q) //가능한 방법 
{
	if (q == route.length()) {
		sum++;
		return;
	}
	for (int i = t; i < length; i++) {
		if (arr[now][i] != route[q]) continue; // 일치 하지 않으면 패스
		if (now == 0) nexts = 1; // 다리 번갈아 가며 이동
		else nexts = 0;
		t = i + 1;
		dfs(nexts, q + 1);
	}
}

int main() {
	cin >> route;
	for (int k = 0; k < 2; k++) {
		string first;
		cin >> first;
		length = first.length();
		arr[k] = first;
	}
	dfs(0, 0); // 악마부터 시작
	t = 0;
	dfs(1, 0); // 천사부터 시작
	cout << sum;
}