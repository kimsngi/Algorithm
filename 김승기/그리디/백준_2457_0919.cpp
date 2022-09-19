#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int stnum;
	int ennum;
	int days;
};
int vecdat[1232][1232];
bool cmp(info a, info b) {
	if (a.ennum < b.ennum) return false;
	if (a.ennum > b.ennum)return true;

	if (a.days < b.days) return false;
	if (a.days > b.days)return true;

	return false;
}

vector<info> fl;
int funcflag;
int cnt;

info flfind(info now) {
	funcflag = 0;
	for (int i = 0; i < fl.size(); i++) {
		info next = fl[i];
		if (now.ennum < next.stnum || now.ennum >= next.ennum)continue;
		
		funcflag = 1;
		return next;
	}

	return now;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;

		cin >> sm >> sd >> em >> ed;

		int stnum = sm * 100 + sd;
		int ennum = em * 100 + ed;

		int days = ennum - stnum;

		if (vecdat[stnum][ennum] == 1)continue;

		vecdat[stnum][ennum] = 1;
		fl.push_back({ stnum,ennum,days });

	}

	sort(fl.begin(), fl.end(), cmp);

	info now = { 0,0,0 };
	for (int i = 0; i < fl.size(); i++) {
		if (fl[i].stnum > 301)continue;

		now = fl[i];
		cnt = 1;
		break;
	}

	if (now.stnum == 0) {
		cout << 0;
		exit(0);
	}


	while (now.ennum < 1200) {

		info next = flfind(now);

		if (funcflag == 0) {
			cout << 0;
			exit(0);
		}
		cnt++;
		now = next;
	}

	cout << cnt;
}