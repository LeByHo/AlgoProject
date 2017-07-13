#include<stdio.h>
char box[1000][1000];
int box1[1000][1000];
int x, y, isGood = 0;
void check(int, int);
int main(void) {
	int bol;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		scanf("%s", &box[i]);
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			box1[i][j] = box[i][j] - '0';
		}
	}
	for (int j = 0; j < y; j++) {
		check(0, j);
	}
	if (isGood == 0)
		printf("NO");
	else
		printf("YES");
}void check(int i, int j) {
	if (i == x)
		++isGood ;
	if (j ==y || j<0 ||i<0|| i==x||box1[i][j]==1)
		return ;
	box1[i][j] = 1;
	check(i, j + 1);
	check(i+1, j);
	check(i, j - 1);
	check(i-1, j);
}
		