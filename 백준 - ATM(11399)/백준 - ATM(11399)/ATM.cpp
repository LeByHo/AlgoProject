#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int main() {
	int N, dp[MAX + 1];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &dp[i]);
	sort(dp, dp + N);
	int sum = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] += dp[i - 1];
		sum += dp[i];
	}
	printf("%d\n", sum);
}

