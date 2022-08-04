#include <iostream>
#include <string>
using namespace std;

int main()
{

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				count1++;
			}
		}
	}

	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j < str3.length(); j++)
		{
			if (str2[i] == str3[j])
			{
				count2++;
			}
		}
	}

	for (int i = 0; i < str3.length(); i++)
	{
		for (int j = 0; j < str1.length(); j++)
		{
			if (str3[i] == str1[j])
			{
				count3++;
			}
		}
	}

	if (count1 == 0 && count2 == 0 && count3 == 0)
	{
		cout << "Perfect";
	}
	else
	{
		cout << "No";
	}
}
