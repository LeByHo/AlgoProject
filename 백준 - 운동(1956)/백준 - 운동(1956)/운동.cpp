#include<cstdio>
#include<algorithm>
using namespace std;

int g[401][401], N, M;
int inf = 1000001;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (g[i][j] == 0 || g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			g[i][j] = inf;
		}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (g[a][b] == 0 || g[a][b] > c)
			g[a][b] = c;
	}

	floyd();

	int ans = inf;
	for (int i = 1; i <= N; i++) {
		if (g[i][i] != 0 && ans > g[i][i])
			ans = g[i][i];
	}

	if (ans == inf)
		printf("%d\n", -1);
	else
		printf("%d\n", ans);

	return 0;
}