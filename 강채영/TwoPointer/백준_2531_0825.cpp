#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, d, k, c;
int menu[30001];
int num[3001];

void solution()
{
	int left = 0;
	int right = k - 1;
	int maxval = -1;

	while (left < n)
	{
		int flag = 0;
		int coupon = 0;
		int cnt = 0;

		for (int i = left; i <= right; i++)
		{
			if (num[menu[i % n]] == 0)
			{
				num[menu[i % n]]++;
				cnt++;
			}
			else if(num[menu[i%n]]==1)
			{
				flag++;
			}
		}

		if (num[c] == 0)
		{
			coupon = 1;
		}

		maxval = max(maxval, cnt + coupon); // flag에 중복갯수를 기재했으므로 계산은 cnt와 coupon으로만 진행
		memset(num, 0, sizeof(num));
		left++;
		right++;
	}
	cout << maxval;
}

int main()
{
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> menu[i];
	}

	solution();
	
}