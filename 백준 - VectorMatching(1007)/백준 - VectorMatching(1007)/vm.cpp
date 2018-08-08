#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
long long INF = 9876543212345;
long long ans;
int n;

struct Point {
	int x;
	int y;
	Point() {
		x = 0; y = 0;
	}
	Point operator + (Point p) {
		Point ans;
		ans.x = x + p.x;
		ans.y = y + p.y;
		return ans;
	}

	Point operator - (Point p) {
		Point ans;
		ans.x = x - p.x;
		ans.y = y - p.y;
		return ans;
	}
	long long scalar() {
		return (long long)x*x + (long long)y*y;
	}
};
Point point[22];

void dfs(int i, Point p, int cnt) {
	if (!cnt) {
		for (int j = i + 1; j <= n; ++j)p = p - point[j];
		ans = min(ans, p.scalar());
		return;
	}
	if (i == n) return;
	for (int j = i + 1; j <= n; ++j) {
		p = p + point[j];
		dfs(j, p, cnt - 1);
		p = p - point[j] - point[j];
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t; --t) {
		Point p;
		ans = INF;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &point[i].x, &point[i].y);
		}
		dfs(0, p, n >> 1);
		printf("%.6lf\n", sqrt(ans));
	}
}