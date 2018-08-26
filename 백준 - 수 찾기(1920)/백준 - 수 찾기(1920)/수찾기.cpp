#include<cstdio>
#include<algorithm>
using namespace std;
int number[1000000];
int cnt, cnt2, f_num, flag = 0;
void search(int left, int right) {
	if (left > right)
		;
	else {
		if (f_num < number[(left + right) / 2])
			search(left, (left + right) / 2 - 1);
		else if (f_num > number[(left + right) / 2])
			search((left + right) / 2 + 1, right);
		else
			flag = 1;
	}
}
int main() {

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &number[i]);
	}
	sort(number, number + cnt);
	scanf("%d", &cnt2);
	for (int i = 0; i < cnt2; i++) {
		flag = 0;
		scanf("%d", &f_num);
		if (f_num<number[0] || f_num>number[cnt - 1])
			printf("0\n");
		else {
			search(0, cnt - 1);
			if (flag)
				printf("1\n");
			else
				printf("0\n");
		}
	}
}