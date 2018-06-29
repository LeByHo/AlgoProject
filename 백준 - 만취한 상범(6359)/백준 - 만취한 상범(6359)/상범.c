#include<stdio.h>
int room[101];
int main() {
	int test, r_count,count=0;
	scanf("%d", &test);
	while (test > 0) {
		count = 0;
		scanf("%d", &r_count);
		for (int i = 1; i <=r_count; i++) {
			for (int j = i; j <= r_count; j=j+i) {
				room[j]++;
			}
		}
		for (int i = 1; i <= r_count; i++) {
			if (room[i] % 2 == 1)
				count++;
		}
		printf("%d\n", count);
		for (int i = 1; i <= r_count; i++) {
			room[i] = 0;
		}
		test--;
	}

}