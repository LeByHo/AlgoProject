#include<cstdio>
#include<math.h>
using namespace std;
int number[5];
int total = 0;
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &number[i]);
		total += pow(number[i], 2);
	}
	printf("%d", total % 10);
	return 0;
}