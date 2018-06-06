#include<stdio.h>
int score[2][100001];
int dp[2][100001];
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	int test,number;
	scanf("%d", &test);
	while (test > 0) {
		scanf("%d", &number);
		for (int i = 0; i < 2; i++) {
			for (int j = 1;  j <= number; j++) {
				scanf("%d", &score[i][j]);
			}
		}
		for (int i = 1; i <=number; i++) {
			if (i == 1) {
				dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + score[0][i]);
				dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + score[1][i]);
			}
			else {
				dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1] + score[0][i]), dp[1][i - 2] + score[0][i]);
				dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 1] + score[1][i]), dp[0][i - 2] + score[1][i]);
			}
		}
		if (dp[0][number] > dp[1][number])
			printf("%d\n", dp[0][number]);
		else
			printf("%d\n", dp[1][number]);

		test--;
	}
}
