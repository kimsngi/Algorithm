#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;

int n;
int number[101];
int visited[101];

int flag = 0;
vector <int> selected;
vector <int> answer;

void dfs(int startnum, int num)
{
	if (visited[num])
	{
		if (startnum == num)
		{
			flag = 1;
			selected.push_back(num);
		}
		return;
	}

	visited[num] = 1;
	dfs(startnum, number[num]);
	if (flag)
	{
		selected.push_back(num);
		selected.push_back(number[num]);
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> number[i];
	}
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 1;
		dfs(i, number[i]);
		memset(visited, 0, sizeof(visited));
		flag = 0;
	}

	sort(selected.begin(), selected.end());
	selected.erase(unique(selected.begin(), selected.end()), selected.end());

	cout << selected.size() << endl;

	for (int i = 0; i < selected.size(); i++)
	{
		cout << selected[i] << endl;
	}
}