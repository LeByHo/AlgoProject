#include <stdio.h>
int d[301][301];
int v[301][301];
int N, M, K;
int main() {
	int start, arrive, cost;
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			d[i][j] = -1;
			v[i][j] = -1;
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &start, &arrive, &cost);
		if (start >=arrive)
			continue;
		if (v[start][arrive] < cost)
			v[start][arrive] = cost;
	}

	d[1][0] = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			for (int k = 1; k <= M -1; k++)
			{
				if (v[j][i] != -1 && d[j][k - 1] != -1)
				{
					if (d[i][k] < d[j][k - 1] + v[j][i])
						d[i][k] = d[j][k - 1] + v[j][i];
				}
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= M - 1; i++) {
		if (max < d[N][i])
			max = d[N][i];
	}
	printf("%d", max);
	return 0;

}