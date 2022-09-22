#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Date {
	int start;
	int end;
};

int N;

vector<Date> v;

bool cmp(Date a, Date b) {
	if (a.start < b.start) return true;
	if (a.start > b.start) return false;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a*100+b,c*100+d });
	}

	sort(v.begin(), v.end(),cmp);

	int endTime = 301; // 기준 위치
	int cnt = 0;

	// 1. 3월1일 이전에 피는 꽃 중에, 지는 시기가 가장 늦은 것을 찾는다
	// 2. 갱신된 endTime보다 일찍 피는 꽃 중에, 지는 시기가 가장 늦는 것을 찾는다
	

	while (endTime <= 1130) {
		int nextEnd = -1;

		// 3월 1일보다 일찍 피는 꽃 중에 지는 시기가 가장 늦은 것 찾기
		for (int i = 0; i < N; i++) {

			if (v[i].start <= endTime) {
				nextEnd = max(nextEnd, v[i].end);
			}
			else break; // 3월1일보다 일찍 피는 꽃이 없다 -> 구간 발생x
		}
		if (nextEnd == -1) break; // 갱신이 안된 경우 -> 구간 발생x 
		else {
			endTime = nextEnd;
			cnt++;
		}

	}
	
	if (endTime > 1130) cout << cnt;
	else cout << 0;

	return 0;
}