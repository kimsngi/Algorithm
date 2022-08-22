#include <iostream>
using namespace std;

int n;
int arr[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 0;
	int right = n - 1;
	int minval = 1234567890;
	

	while (left < right)
	{
		int sum = arr[left] + arr[right];


		if (sum == 0)
		{
			minval = 0;
			break;
		}

		if (sum != 0)
		{
			if (abs(minval) > abs(sum))
			{
				minval = sum;
			}

			if(sum>0)
			{
				right--;
			}

			else if(sum < 0)
			{
				left++;
			}
		}
		
	}
	cout << minval;
	
}