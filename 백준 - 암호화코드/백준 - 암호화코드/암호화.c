#include<stdio.h>
int code[5000];
int main() {
	int count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &code[i]);
	}

	return 0;
}