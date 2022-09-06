#include <iostream>
#include <algorithm>
using namespace std;
struct info {
	int price;
	int value;
};
bool cmp(info a, info b) {

	if (a.price < b.price) return true;
	if (a.price > b.price) return false;
	return false;

}
info pr[100000];
int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >>pr[i].price >> pr[i].value;
	}
	sort(pr, pr + n, cmp);

	int left = 0;
	int right = 0;
	long long ans = 0;
	long long sum = pr[0].value;
	while (left <= n - 1) {

		if (pr[right].price - pr[left].price <  d) {
			ans = max(ans,sum);
			if (right < n - 1) {
				right++;
				sum += pr[right].value;
			}
			else {
				break;
			}
		}
		else {
			sum -= pr[left].value;
			left++;
		}
	
		//int de = 1;
	}

	cout << ans;
}