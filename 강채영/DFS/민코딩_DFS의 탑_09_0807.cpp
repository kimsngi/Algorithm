#include <iostream>
#include <vector>
using namespace std;

int cntNode, cntEdge, x;
vector <int> v_down[1000000];
vector <int> v_up[1000000];
int visited[1000000];
int visited2[1000000];
int cnt_down;
int cnt_up;

void dfs_down(int now)
{
	if (visited[now]==1)
	{
		return;
	}

	visited[now] = 1;
	cnt_down++;

	for (int i = 0; i < v_down[now].size(); i++)
	{
		int next = v_down[now][i];
		dfs_down(next);
	}
}

void dfs_up(int now)
{
	if (visited2[now] == 1)
	{
		return;
	}
	visited[now] = 1;
	cnt_up++;

	for (int i = 0; i < v_up[now].size(); i++)
	{
		int next = v_up[now][i];
		dfs_up(next);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cntNode >> cntEdge >> x;

	for (int i = 0; i < cntEdge; i++)
	{
		int from, to;
		cin >> from >> to;
		v_down[from].push_back(to);
		v_up[to].push_back(from);
	}

	dfs_down(x);
	dfs_up(x);
	
	cout << cnt_up << endl;
	cout << cntNode - cnt_down + 1;
}