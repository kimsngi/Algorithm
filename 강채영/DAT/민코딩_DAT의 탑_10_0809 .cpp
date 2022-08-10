#include <iostream>
using namespace std;

int height[1000001];
int index[1000001];
int arr[1000001];
int testcase;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> height[j];
		}
		for (int j = 0; j < n; j++)
		{
			cin >> index[j];
		}

		for (int j = 0; j < n; j++)
		{
			arr[index[j] - 1] = height[j];
		}
		
		int flag = 0;

		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				flag++;
			}
		}
		
		if (flag == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		
	}
}