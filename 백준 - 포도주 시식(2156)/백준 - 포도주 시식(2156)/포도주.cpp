#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;

int dp[10001];
int grape[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &grape[i]);
	}
	dp[1] = grape[1];
	dp[2] = grape[2] + grape[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + grape[i] + grape[i - 1], dp[i - 1]);
		dp[i] = max(dp[i], dp[i - 2] + grape[i]);
	}
	printf("%d", dp[n]);
	return 0;
}