#include<cstdio>
int dp[11];
int main() {
	int test,n;
	scanf("%d", &test);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < test; i++) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}