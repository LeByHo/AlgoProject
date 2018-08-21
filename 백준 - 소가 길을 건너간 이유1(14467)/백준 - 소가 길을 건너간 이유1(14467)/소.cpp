#include<stdio.h>
#include<algorithm>
using namespace std;
int n, x, y, cnt = 0;
int a[15];
int main(void)
{
	scanf("%d", &n);
	fill(a, a + 12, 2);
	for (; n>0; n--)
	{
		scanf("%d %d", &x, &y);
		if (a[x] == 2) a[x] = y;
		else if (a[x] != y) { a[x] = y; cnt++; }
	}
	printf("%d", cnt);
}
