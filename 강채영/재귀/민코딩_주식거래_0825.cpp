#include <iostream>
#include <queue>
using namespace std;

int arr[20][20];
int ms, ma;
int n, l;
int sum;

struct Info
{
	int month;
	int index;
};

struct Sell
{
	int month;
	int index;
	int num;
};

queue <Info> buyq;
queue <Sell> sellq;

void buy()
{
	while (!buyq.empty())
	{
		Info buy = buyq.front();
		int n = sum / arr[buy.index][buy.month];
		sellq.push({buy.index, buy.month, n });
		sum = sum - (n * arr[buy.index][buy.month]);

		buyq.pop();
	
	}
}

void sell()
{
	while (!sellq.empty())
	{
		Sell now = sellq.front();
		sellq.pop();

		sum += (arr[now.index][now.month + 1]) * now.num;		
	}
}

int func(int now)
{
	sum += ma;

	if (now > l)
	{
		return sum;
	}

	if (sellq.size() > 0)
	{
		sell();
	}
	

	for (int y = 0; y < n; y++)
	{
		int next = now + 1;
		if (arr[y][next] - arr[y][now] <= 0)
		{
			continue;
		}
		else
		{
			buyq.push({ now, y });
		}
	}

	if (buyq.size() > 0)
	{
		buy();
	}
	
	func(now + 1);	
}

int main()
{
	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++)
	{
		cin >> ms >> ma;
		cin >> n >> l;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x <= l; x++)
			{
				cin >> arr[y][x];
			}
		}

		sum = ms;
		int result = func(0);

		cout << (ms + (ma * l)) - result;

	}
}