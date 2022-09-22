#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int n;
int mp, mf, ms, mv;
int p, f, s, v, cost;

struct Info
{
	int p;
	int f;
	int s;
	int v;
	int cost;
};

vector <Info> vect;
vector <int> answer;
vector <int> path;
int mincost = 1234567890;

int check(int p, int f, int s, int v)
{
	if (p >= mp && f >= mf && s >= ms && v >= mv)
	{
		return 1;
	}
	return 0;
}

void dfs(int node, int p, int f, int s, int v, int cost)
{
	if (node == n)
	{
		if (check(p, f, s, v) == 1)
		{
			if (mincost > cost)
			{
				answer = path;
				mincost = cost;
			}
			else if (mincost == cost && answer > path)
			{
				answer = path;
				mincost = cost;
			}
		}
		return;
	}

	dfs(node + 1, p, f, s, v, cost);
	path.push_back(node);
	dfs(node + 1, p + vect[node].p, f + vect[node].f, s + vect[node].s, v + vect[node].v, cost + vect[node].cost);
	path.pop_back();
}

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		string a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		p = stoi(a);
		f = stoi(b);
		s = stoi(c);
		v = stoi(d);
		cost = stoi(e);

		vect.push_back({ p,f,s,v,cost });
	}

	dfs(0, 0, 0, 0, 0, 0);

	if (mincost == 1234567890)
	{
		cout << -1;
		return 0;
	}
	else
	{
		cout << mincost << endl;
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] + 1 << " ";
		}
	}

}