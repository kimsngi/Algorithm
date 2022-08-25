#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[10001];
int result[10001];
int sum;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n-1; i++)
	{
		result[i] = arr[i + 1] - arr[i];
	}
	
	sort(result, result + n - 1);

	for (int i = 0; i < n-1-(k-1); i++)
	{
		sum += result[i];
	}

	cout << sum;
}