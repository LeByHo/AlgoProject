//ÇÁ¸²
#include<cstdio>
#include<iostream>
using namespace std;

int N, MAX = 999999999;
int g[1001][1001];
int dist[1001];
int prim() {
	int i, j, mini, idx, sum = 0;

	for (i = 1; i <= N; i++)
		dist[i] = g[1][i];
	dist[1] = -1;

	for (int j = 1; j < N; j++) {
		mini = MAX;
		for (i = 1; i <= N; i++) {
			if (dist[i] != -1 && dist[i] < mini) {
				mini = dist[i];
				idx = i;
			}
		}
		sum += mini;
		dist[idx] = -1;

		for (i = 1; i <= N; i++) {
			if (dist[i] > g[idx][i])
				dist[i] = g[idx][i];
		}
	}
	return sum;
}

int main() {
	int M, a, b, c, i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			g[i][j] = MAX;
			if (i == j)
				g[i][j] = 0;
		}
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
	}

	printf("%d\n", prim());

	return 0;
}