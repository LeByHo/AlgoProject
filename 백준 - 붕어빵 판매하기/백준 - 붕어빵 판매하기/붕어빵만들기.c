#include<stdio.h>
int max[1001];
int price[1001];
int main() {
	int count;
	scanf("%d", &count);
	for (int i = 1; i <= count; i++) {
		scanf("%d", &price[i]);
	}
	max[0] = 0;
	for (int i = 1; i <= count; i++) {
		max[i] = 0;
		for (int j = 1; j <= i; j++) {
			if (max[i] < max[i-j] + price[j]) {
				max[i] = max[i-j] + price[j];
			}
		}
	}
	printf("%d", max[count]);
	return 0;
}