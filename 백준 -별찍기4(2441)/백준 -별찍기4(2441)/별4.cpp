#include<cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = n; i>0; i--) {
		for (int j = (n - i); j>0; j--) {
			printf(" ");
		}for (int j = 0; j<i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}