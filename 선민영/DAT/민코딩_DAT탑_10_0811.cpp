#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int arr[1000001];
int brr[1000001];
int cnt[251];
int t;
int p;
int flag;
struct Node {
	int height;
	int order;
};
priority_queue<Node>q;
priority_queue<Node>qq;
bool operator < (Node a, Node b) {
	if (a.order > b.order)
		return true;
	if (a.order < b.order)
		return false;
	return false;
}
void go() {
	t = 0;
	p = 1;
	flag = 0;
	int num;
	cin >> num;
	for (int k = 0; k < num; k++) {
		cin >> arr[k];
		cnt[arr[k]]++;
	}
	for (int i = 250; i >= 0; i--) {
		if (t == num) break;
		while (cnt[i] > 0) {
			qq.push({ i, p });
			cnt[i]--;
			p++;
			t++;
		}
	}
	for (int k = 0; k < num; k++) {
		cin >> brr[k];
	}
	for (int k = 0; k < num; k++) {
		q.push({ arr[k], brr[k] });
	}
	for (int k = 0; k < num; k++) {
		Node now = q.top(); q.pop();
		Node next = qq.top(); qq.pop();
		if (now.height != next.height) flag = 1;
	}
	if (flag == 1)cout << "NO"<<"\n";
	else cout << "YES"<<"\n";

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		go();
	}
}