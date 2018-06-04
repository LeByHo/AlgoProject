#include<stdio.h>
int N;
int adj[20][20], chk[20][20];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
			chk[i][j] = adj[i][j];
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					printf("-1");
					return 0;
				}

				if (i == k || j == k) continue;
				if (adj[i][j] == adj[i][k] + adj[k][j]) {
					chk[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			ans += chk[i][j];
		}
	}
	printf("%d", ans);
	return 0;
}