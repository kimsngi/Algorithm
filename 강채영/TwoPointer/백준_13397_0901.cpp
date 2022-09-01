#include <iostream>
#include <vector>
using namespace std;

int n, m;
int maxval;
int sum;
int arr[5001];

int maketeam(int num)
{
	int cnt = 1;
	int minval = 1234567890;
	int maxval = -1234567890;
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		minval = min(minval, arr[i]);
		maxval = max(maxval, arr[i]);
		if (maxval - minval > num)
		{
			cnt++;
			minval = arr[i];
			maxval = arr[i];
			index = i;
		}
	}
	if (cnt <= m)
	{
		return 1;
	}
}

void psearch()
{
	int left = 0;
	int right = maxval;
	int ans = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int flag = maketeam(mid);
		if (flag == 1)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxval = max(maxval, arr[i]);
	}

	psearch();
}