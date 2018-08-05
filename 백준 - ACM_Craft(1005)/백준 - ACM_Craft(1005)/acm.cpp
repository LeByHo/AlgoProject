#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int time[1001], in[1001];
int t, n, k, a, b, w;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &time[i]);
			in[i] = 0;
		}

		vector<vector<int>> vec(n + 1);
		for (int i = 0; i < k; ++i) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			in[b]++;
		}


		vector<int> ans(n + 1);
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (!in[i]) {
				q.push(i);
				ans[i] = time[i];
			}
		}

		scanf("%d", &w);
		while (!q.empty()) {
			int m = 0;
			int cur = q.front();
			q.pop();
			if (cur == w)
				break;

			for (auto next : vec[cur]) {
				in[next]--;

				if (ans[next] < ans[cur] + time[next])
					ans[next] = ans[cur] + time[next];

				if (!in[next])
					q.push(next);
			}
		}
		printf("%d\n", ans[w]);
	}
	return 0;
}
