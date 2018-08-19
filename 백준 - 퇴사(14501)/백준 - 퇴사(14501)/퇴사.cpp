#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 51

using namespace std;

int day[MAX_SIZE];
int cost[MAX_SIZE];
int dp[MAX_SIZE];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &day[i], &cost[i]);

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int next1 = i + day[i];
		int next2 = i + 1;

		if (next1 <= n + 1) dp[next1] = max(dp[next1], dp[i] + cost[i]);
		if (next2 <= n + 1) dp[next2] = max(dp[next2], dp[i]);

		ret = max(max(ret, dp[next1]), dp[next2]);
	}

	printf("%d\n", ret);

	return 0;
}
