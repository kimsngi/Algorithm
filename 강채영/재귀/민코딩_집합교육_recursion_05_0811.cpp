#include <iostream>
using namespace std;

int n, m;
int arr[300][300];
int path[300];


void func(int level)
{

	// 같은 수가 있으면 제외시키는 조건
 
	if (level == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < m; i++)
	{
		path[level] = i;
		func(level + 1);
		path[level] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	func(0);

}