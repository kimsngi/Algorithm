#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, d;


struct Node
{
	long long p;
	long long v;
};

vector <Node> friends;

bool cmp(Node a, Node b)
{
	if (a.p < b.p)
	{
		return true;
	}
	if (a.p > b.p)
	{
		return false;
	}
	return false;
}

int find()
{
	long long left = 0;
	long long right = 0;  
	long long sum = 0;
	long long maxval = -1;

	while (left <= right && right<=n)
	{

		if (abs(friends[right].p - friends[left].p) < d)
		{
			right++;
			sum = sum + friends[right].v;
		}
		else
		{
			sum = sum - friends[left].v;
			left++;
		}

		maxval = max(maxval, sum);
	}

	return maxval;
}

int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		long long p, v;
		cin >> p >> v;
		friends.push_back({ p,v });
	}

	sort(friends.begin(), friends.end(), cmp);

	int result = find();

	cout << result;
}