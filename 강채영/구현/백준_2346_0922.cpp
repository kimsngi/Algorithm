#include <iostream>
#include <vector>
using namespace std;

int n;
struct Info
{
	int index;
	int value;
};

vector <Info> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		v.push_back({ i + 1, value });
	}

	while (!v.empty())
	{
		cout << v.front().index << " ";
		int nextvalue = v.front().value;
		v.erase(v.begin());

		if (nextvalue > 0)
		{
			for (int i = 0; i < nextvalue - 1; i++)
			{
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
		else
		{
			for (int i = 0; i < abs(nextvalue); i++)
			{
				v.insert(v.begin(), v.back());
				v.erase(v.end() - 1);
			}
		}
	}
	return 0;
}