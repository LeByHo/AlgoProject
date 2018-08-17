#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 501
using namespace std;
int dp[MAX][MAX];
int cost[MAX][MAX];
int n,res=0;
void DP(int i, int j,int flag){
	if (!dp[i][j]) {
		dp[i][j]++;
		
		if (i - 1 >= 1 && cost[i][j] < cost[i - 1][j]) {
			if(dp[i][j]==1)
				dp[i][j]++;
			DP(i - 1, j,1);
			if (dp[i - 1][j] >=dp[i][j])
				dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
		}
		if (i + 1 <= n && cost[i][j] < cost[i + 1][j]) {
			if (dp[i][j] == 1)
				dp[i][j]++;
			DP(i + 1, j,2);
			if (dp[i+1][j] >= dp[i][j])
				dp[i][j]=max(dp[i][j],dp[i+1][j]+1);
		}
		if (j - 1 >= 1 && cost[i][j] < cost[i][j - 1]) {
			if (dp[i][j] == 1)
				dp[i][j]++;
			DP(i, j - 1,3);
			if (dp[i][j-1] >= dp[i][j])
				dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
		}
		if (j + 1 <= n && cost[i][j]<cost[i][j + 1]) {
			if (dp[i][j] == 1)
				dp[i][j]++;
			DP(i, j + 1, 4);
			if (dp[i][j + 1] >= dp[i][j])
				dp[i][j] =max(dp[i][j], dp[i][j +1] + 1);
		}
		
	}
	else {
		if(flag==1)
			dp[i+1][j] = max(dp[i+1][j], 1+ dp[i][j]);
		else if(flag==2)
			dp[i - 1][j] = max(dp[i - 1][j], 1+ dp[i][j]);
		else if(flag==3)
			dp[i][j+1] = max(dp[i][j+1], 1 + dp[i][j]);
		else
			dp[i ][j-1] = max(dp[i ][j-1], 1 + dp[i][j]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(!dp[i][j])
				DP(i, j,0);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = max(res, dp[i][j]);
		}
	}
	printf("%d", res);
	return 0;
}