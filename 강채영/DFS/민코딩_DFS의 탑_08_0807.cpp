#include <iostream>
#include <vector>
using namespace std;

string ch;
string str[2];
int cnt;

void dfs(int level, int now, int version)
{
	if (level == ch.length())
	{
		cnt++;
		return;
	}

	if (version == 0)
	{
		for (int i = now; i < str[version].size(); i++)
		{
			if (ch[level] == str[version][i])
			{
				int next = i + 1;
				version = 1;
				dfs(level + 1, next, version);
				version = 0;
			}
		}
	}

	if (version == 1)
	{
		for (int i = now; i < str[version].size(); i++)
		{
			if (ch[level] == str[version][i])
			{
				int next = i + 1;
				version = 0;
				dfs(level + 1, next, version);
				version = 1;
			}
		}
	}


}

int main()
{
	cin >> ch;
	cin >> str[0];
	cin >> str[1];

	dfs(0, 0, 0);
	dfs(0, 0, 1);

	cout << cnt;
}