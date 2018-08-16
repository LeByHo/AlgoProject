#include <iostream>
using namespace std;
int main() {
	int arr[5], small = 2001, small2 = 2001;
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		if (arr[i] < small)
		{
			small = arr[i];
		}
	}
	for (int i = 3; i <= 4; i++)
	{
		cin >> arr[i];
		if (arr[i] < small2)
		{
			small2 = arr[i];
		}
	}
	cout << small + small2 - 50 << '\n';
}