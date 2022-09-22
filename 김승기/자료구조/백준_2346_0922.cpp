#include <iostream>
#include <deque>
using namespace std;
deque<pair<int,int>> dq;
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int pnum;
		cin >> pnum;
		dq.push_back({ i+1,pnum });
	}

	int now = 1;
	int nowid = now - 1;
	
	while (!dq.empty()) {

		cout << dq[nowid].first << " ";

		int nextid = nowid + dq[nowid].second;

		dq.erase(dq.begin() + nowid);

		if (dq.empty())break;

		int dqsize = dq.size();
		if (nextid < 0) {
			
			while (nextid < 0) {
				nextid += dqsize;
			}
		}
		else if (nextid > dqsize - 1 || nowid < nextid) {
			nextid--;
			while (nextid > dqsize - 1) {
				nextid -= dqsize;
			}
		}

		nowid = nextid;

	}

}