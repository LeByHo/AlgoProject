#include<stdio.h>
int sample[13],stack[6];
int head=0,number;

void push(int num) {
	stack[head++]= sample[num];
}
void pop() {
	stack[--head] = 0;
}
void n_print() {
	for (int i = 0; i < 6; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void choice(int index) {
	if (head == 6) {
		n_print();
		pop();
		return 0;
	}
	if (index == number)
		return 0;
	
	for (int i = index; i < number; i++) {
		if (head == 0) {
			if ((number - i )+ head < 6)
				break;
			else {
				push(i);
				choice(i + 1);
			}
		}
		else {
			if ((number - i) + head < 6)
				break;
			else {
				push(i);
				choice(i + 1);
			}
		}
	}
	pop();
}

int main() {
	while (1) {
		scanf("%d", &number);
		if (number == 0)
			break;
		else {
			head = 0;
			for (int i = 0; i < number; i++) {
				scanf("%d", &sample[i]);
			}
			choice(0);
		}
	}
	return 0;
}