#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX_N 100
using namespace std;

int n, m, s, v, b[MAX_N + 1], visited[MAX_N + 1];
pair<double, double> mouse[MAX_N + 1];
pair<double, double> hole[MAX_N + 1];
vector<vector<int>> vt;
double distance(pair<double, double> x, pair<double, double> y) {
	return sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}
bool dfs(int here) {
	if (visited[here])return false;
	visited[here] = true;
	for (int there : vt[here]) {
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return true;
		}
	}
	return false;
}
int match() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ret++;
	}
	return ret;
}
int main() {
	scanf("%d %d %d %d", &n, &m, &s, &v);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &mouse[i].first, &mouse[i].second);
	for (int i = 1; i <= m; i++)
		scanf("%lf%lf", &hole[i].first, &hole[i].second);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			double dist = distance(mouse[i], hole[j]);
			if ((double)s*v >= dist)
				vt[i].push_back(j);
		}
	}
	printf("%d\n", n - match());
	return 0;
}
