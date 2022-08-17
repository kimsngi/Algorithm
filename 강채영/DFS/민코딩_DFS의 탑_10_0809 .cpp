#include <iostream>
#include <vector>
using namespace std;

int cntNode, num1, num2;
int visited[100001];
int sum_max;
int minval = 1234567890;
int max_length = -1234567890;
int len[100001];

struct Node
{
	int to;
	int length;
};

vector <Node> v[100001];

void dfs(int now)
{

	visited[now] = 1;

	if (now == num2) 
	{
		if (sum_max < minval)
		{
			minval = sum_max;
		}
	}
	

	for (int i = 0; i < v[now].size(); i++)
	{
		Node next = v[now][i];

		if (visited[next.to] == 1)
		{
			continue;
		}
		
		if (sum_max + next.length > minval)
		{
			continue;
		}

		if (next.length > max_length)    // 경로 중 최대 길이를 구함
		{
			max_length = next.length;
		}

		visited[next.to] = 1;
		sum_max += next.length;
		dfs(next.to);
		visited[next.to] = 0;
		sum_max -= next.length;
	}

}

int main()
{
	cin >> cntNode >> num1 >> num2;
	for (int i = 0; i < cntNode-1; i++)
	{
		int from, to, length;
		cin >> from >> to >> length;
		v[from].push_back({ to,length });
		v[to].push_back({ from,length });
	}

	dfs(num1);

	if (num1 == num2)  // num1 == num2 일 경우를 따로 추가함
	{
		cout << 0;
	}
	else
	{
		cout << minval - max_length;
	}
		
}