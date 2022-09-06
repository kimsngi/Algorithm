#include <iostream>
#include <queue>
using namespace std;

int h, w;
int arr[501][501];
int water[501]; 
int sum;

void solution(int level)
{
	int indexs = w;
	int indexe = w;
	if (level == h)
	{
		return;
	}

	for (int i = 0; i < w; i++)
	{
		if (arr[level][i] == 1)
		{
			indexs = i;
			break;
		}
	}

	for (int i = 0; i < indexs; i++)
	{
		arr[level][i] = -1;
	}

	for (int i = w - 1; i >= 0; i--)
	{
		if (arr[level][i] == 1)
		{
			indexe = i;
			break;
		}
	}

	for (int i = indexe+1; i<w  ; i++)
	{
		arr[level][i] = -1;
	}

	solution(level + 1);
}

void find()
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (arr[y][x] == 0)
			{
				sum++;
			}
		}
	}
}

int main()
{
	cin >> h >> w;
	for (int i = 0; i < w; i++)
	{
		int level;
		cin >> level;
		water[i] = level;
		for (int j = level; j >= 1; j--)
		{
			arr[h - j][i] = 1;
		}
	}

	solution(0);

	find();

	cout << sum;
	
}