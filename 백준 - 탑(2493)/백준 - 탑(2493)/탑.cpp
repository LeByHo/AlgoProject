#include<iostream>
using namespace std;
int main(void)
{
	long long stack[500001];
	int stackpointer = 0;
	long long input[500001];
	long long ans[500001] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (stackpointer > 0 && input[i] >= input[stack[stackpointer - 1]])
		{
			ans[stack[(stackpointer--) - 1]] = i + 1;
		}
		stack[stackpointer++] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}