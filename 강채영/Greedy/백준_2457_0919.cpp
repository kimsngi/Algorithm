#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int temp_s = 301;
int temp_e = 301;
int temp = 301;
int flag;
int cnt;

struct Info
{
	int start;
	int end;
};

vector <Info> flower;

bool cmp(Info a, Info b)
{
	if (a.start < b.start)
	{
		return true;
	}
	if (a.start > b.start)
	{
		return false;
	}
	return false;
}

void func()
{
	for (int i = 0; i < n; i++)
	{
		if (temp_s >= flower[i].start)
		{
			temp = max(temp, flower[i].end);
			if (temp > 1130)
			{
				flag = 1;
				break;
			}
		}
		else
		{
			temp_s = temp;
			cnt++;
			if (temp_s >= flower[i].start)
			{
				temp = flower[i].end;
				if (temp > 1130)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	if (flag == 0)
	{
		cout << 0;
	}
	else
	{
		cout << cnt + 1;
	}


}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int startM, startD, endM, endD;
		cin >> startM >> startD >> endM >> endD;
		int start = startM * 100 + startD;
		if (start < 301)
		{
			start = 301;
		}
		int end = endM * 100 + endD;
		if (end > 1201)
		{
			end = 1201;
		}
		flower.push_back({ start,end });
	}

	sort(flower.begin(), flower.end(), cmp);

	func();

}