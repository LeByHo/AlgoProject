#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX_N = 3e5;
typedef long long ll;
int n, k, c[MAX_N];
ll r;
pair<int, int> p[MAX_N];
priority_queue<int> pq;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].first, &p[i].second);
	for (int i = 0; i < k; i++) scanf("%d", c + i);
	sort(p, p + n);
	sort(c, c + k);
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && p[j].first <= c[i]) pq.push(p[j++].second);
		if (!pq.empty()) {
			r += pq.top();
			pq.pop();
		}
	}
	printf("%lld", r);
	return 0;
}