#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int cntNode;
vector<int> v[51];
vector<int> result;
vector<int> student;

struct Node
{
	int node;
	int level;
};

queue<Node>q;
int dist[51];
int visited[51];

int bfs(int start)
{
	q.push({ start, 0 });
	int maxlevel = 0;
	memset(visited, 0, sizeof(visited));
	visited[start] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		maxlevel = max(maxlevel, now.level);

		for (int i = 0; i < v[now.node].size(); i++)
		{
			int next = v[now.node][i];
			if (visited[next] > 0)
			{
				continue;
			}
			visited[next] = 1;
			q.push({ next, now.level + 1 });
		}
	}
	return maxlevel;
}

int main()
{
	cin >> cntNode;
	while (1)
	{
		int from, to;
		cin >> from >> to;
		if (from == -1 && to == -1)
		{
			break;
		}
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= cntNode; i++)
	{
		result.push_back(bfs(i));
	}

	int minval = 1234567890;
	int cnt = 0;

	for (int i = 0; i < result.size(); i++)
	{
		minval = min(minval, result[i]);
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == minval)
		{
			cnt++;
			student.push_back(i);
		}
	}

	cout << minval << " " << cnt << endl;
	for (int i = 0; i < student.size(); i++)
	{
		cout << student[i] + 1 << " ";
	}

}