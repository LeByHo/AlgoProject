#include<stdio.h>
int box[100][100];
int c[100];
int count = 0;
int main(void) {
	int test,hor,ver,a;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		count = 0;
		scanf("%d %d", &ver, &hor);
		for (int j = 0; j < ver; j++) {
			for (int k = 0; k < hor; k++) {
				scanf("%d", &box[j][k]);
				if (box[j][k] == 1) {
					c[k] = c[k] + 1;
					count = count + ver - c[k]-j;	
				}
			}
		}
		printf("%d\n", count);
		for (int j = 0; j < hor; j++) {
			c[j] = 0;
		}
	}
	return 0;
}