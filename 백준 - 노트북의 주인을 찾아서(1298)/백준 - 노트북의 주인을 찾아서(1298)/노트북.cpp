#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int v[105], b[5005], n, m, cnt;
vector<int> adj[105];

int DFS(int k) {
	if (v[k]) return 0;
	v[k] = 1;
	for (auto i : adj[k]) {
		if (!b[i] || DFS(b[i])) {
			b[i] = k;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, c;
		scanf("%d %d", &a, &c);
		adj[a].push_back(c);
	}
	for (int i = 1; i <= n; i++) {
		fill(v, v + 105, 0);
		if (DFS(i)) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
