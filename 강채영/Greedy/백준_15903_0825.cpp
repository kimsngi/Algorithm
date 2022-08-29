#include <iostream>
#include <queue>
using namespace std;

long long n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void solution()
{
	long long a = pq.top();
	pq.pop();
	long long b = pq.top();
	pq.pop();

	long long c = a + b;
	pq.push(c);
	pq.push(c);
}

long long count()
{
	long long sum = 0;

	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++)
	{
		solution();
	}

	long long result = count();
	cout << result;

}