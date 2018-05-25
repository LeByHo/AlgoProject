#include<stdio.h>
int weight[1000];
int main() {
	int count, number = 1, flag = 0, total = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &weight[i]);
		total += weight[i];
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (weight[i] > weight[j])
			{
				int temp;
				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;
			}
		}
	}
	int sum = 1;
		if (weight[0]!=1) {
			printf("1");
		}
		else {
			for (int j = 1; j < count; j++) {
				if (sum + 1 < weight[j])
					break;
				sum += weight[j];
			}
			printf("%d", sum + 1);
		}
	return 0;
}