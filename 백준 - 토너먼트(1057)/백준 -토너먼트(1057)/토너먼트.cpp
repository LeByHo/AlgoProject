#include<cstdio>
using namespace std;
int main(void) {
	int totalmember;
	int imm, kim;
	int count = 0;

	scanf("%d %d %d", &totalmember, &kim, &imm);

	if (totalmember < kim || totalmember < imm) {
		count = -1;
	}
	else {
		while (kim != imm) {
			kim = (kim + 1) / 2;
			imm = (imm + 1) / 2;
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

