#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200001];


int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];		
	}

	sort(arr, arr+n);

	int left = 0;
	int right = arr[n - 1] - arr[0];
	int ans = -1;

	while (left <= right)
	{
		int mid = (right + left) / 2;
		int cnt = 1;
		int start = arr[0];

		for (int i = 1; i < n; i++)
		{
			if (arr[i] - start >= mid)
			{
				cnt++;
				start = arr[i];
			}
		}

		if (cnt >= c)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
}