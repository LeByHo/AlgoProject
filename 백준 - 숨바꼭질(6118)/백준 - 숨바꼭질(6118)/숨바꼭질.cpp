#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int n_ = 20000 + 2;

int n, m, a, b, c, dst[n_];
vector<int> gph[n_];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, u, v; i < m; i++) {
		scanf("%d %d", &u, &v);
		gph[u].push_back(v);
		gph[v].push_back(u);
	}

	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int nxt : gph[now]) if (!dst[nxt]) {
			que.push(nxt);
			dst[nxt] = dst[now] + 1;
			b = max(b, dst[nxt]);
		}
	}

	for (int i = 2; i <= n; i++) if (dst[i] == b) {
		if (!a) a = i; c++;
	}

	printf("%d %d %d\n", a, b, c);

	return 0;
}