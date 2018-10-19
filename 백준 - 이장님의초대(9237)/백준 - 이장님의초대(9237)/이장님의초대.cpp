#include<cstdio>
#include<algorithm>
using namespace std;
int n;

bool desc(int a, int b){
	return a > b;
}

int main()
{
	int i, t;
	int max=1;
	int arr[100001];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr+n+1, desc);
	for (i = 1; i <= n; i++)
	{
		if (max<arr[i] + i)
			max = arr[i] + i;
	}
	printf("%d", max+1);
	return 0;
}