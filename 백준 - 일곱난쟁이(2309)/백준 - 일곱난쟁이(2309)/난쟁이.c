#include<stdio.h>
int sample[9], stack[7];
int total = 0,head=0,flag =0;
void push(int num) {
	stack[head++] = sample[num];
	total += sample[num];
}
void pop() {
	total= total- stack[head-1];
	stack[--head] = 0;
}
void QuickSort(int left, int right) {
	int L = left, R = right;
	int temp;
	int pivot = sample[(left + right) / 2];

	while (L <= R) {
		while (sample[L] < pivot)
			L++;
		while (sample[R] > pivot)
			R--;


		if (L <= R) {
			if (L != R) {
				temp = sample[L];
				sample[L] = sample[R];
				sample[R] = temp;
				}
			L++; R--;
		}
		if (left < R)
			QuickSort(left, R);
		if (L < right)
			QuickSort(L, right);
	}
}
void n_print() {
	for (int i = 0; i < 7; i++) {
		printf("%d\n", stack[i]);
	}
}

void choice(int index) {
	if (flag == 1)
		return 0;
	if (head == 7) {
		if (total == 100) {
			n_print();
			flag == 1;
			return 0;
		}
		else {
			pop();
			return 0;
		}
	}
	if (index == 9) {
		pop();
		return 0;
	}
	for (int i = index; i < 9; i++) {
		if (head == 0) {
			if (i == 2) {
				n_print();
				flag == 1;
				return 0;
			}
			else {
				push(i);
				choice(i + 1);
			}
		}
		else {
			push(i);
			choice(i + 1);
		}
	}
	pop();
}

int main() {
	int count = 0;
	while (count < 9) {
		scanf("%d", &sample[count]);
		count++;
	}
	QuickSort(0, 8);
	choice(0);

	return 0;
}