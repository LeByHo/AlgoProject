#include <iostream>
#include <string>
using namespace std;

int check();

int val = 0;
string cl;
unsigned long long int res[11];		//res는 결과값을 출력하기 위한 배열

int main()
{
	for (int i = 0; i < 11; i++)
		res[i] = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> cl;
		val = check();

		if (i != 2)
		{
			res[i] = check();
		}

		if (i == 2)
		{
			if (res[0] == 0 && res[1] == 0)
			{
				cout << "0";
			}
			else if (res[0] == 0)
			{
				for (int j = 1; j < val + 2; j++)
				{
					cout << res[j];
				}
			}
			else
			{
				for (int j = 0; j < val + 2; j++)
				{
					cout << res[j];
				}
			}
		}
	}
	cout << endl;
	return 0;
}
int check()
{
	if (cl == "black") { return 0; }
	else if (cl == "brown")	return 1;
	else if (cl == "red")	return 2;
	else if (cl == "orange")	return 3;
	else if (cl == "yellow")	return 4;
	else if (cl == "green")	return 5;
	else if (cl == "blue")	return 6;
	else if (cl == "violet")	return 7;
	else if (cl == "grey")	return 8;
	else if (cl == "white")	return 9;
}