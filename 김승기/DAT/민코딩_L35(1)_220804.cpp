#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {

	string sen;
	cin >> sen;

	priority_queue<char> t;

	for (int i = 0; i < sen.size(); i++) {

		t.push(sen[i]);
	}


	while (!t.empty()) {
		char out = t.top();
		t.pop();
		cout << out;
	}
}