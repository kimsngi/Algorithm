#include <iostream>
#include <string>
using namespace std;

int n;
int DAT[10000];
string name[10000];
string no_name[10000];

void func(int number)
{
	if (DAT[number] == 0)
	{
		cout << number << " " << "ERROR" << endl;
	}
	else if (DAT[number] %2== 1)
	{
		cout << number << " " << name[number] << " " << "ENTER" << endl;
		DAT[number]++;
	}
	else if (DAT[number] % 2 == 0)
	{
		cout << number << " " << name[number] << " " << "EXIT" << endl;
		DAT[number]++;
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;
		if (index == 1)
		{
			int number;
			cin >> number;

			if (DAT[number] >= 1)
			{
				cin >> no_name[number];
				cout << number << " " << "ERROR" << endl;
			}
			else if(DAT[number] == 0)
			{
				DAT[number] = 1;
				cin >> name[number];
				cout << number << " "<< "OK"<<endl;
				
			}
			
			
		}
		else if (index == 2)
		{
			int number2;
			cin >> number2;
			func(number2);
		}
		
	}
}