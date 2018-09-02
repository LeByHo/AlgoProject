#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;

const int n_ = 1e3 + 1;

int n, k;
int a[n_], vst[n_], cyc[n_], scc[n_], dph[n_], dp[n_];
vector<int> b[n_];

int c_dfs(int now, int dep, int num) {
	vst[now] = num, dph[now] = dep;
	if (vst[a[now]] == num) return dph[now] - dph[a[now]] + 1;
	return c_dfs(a[now], dep + 1, num);
}

int s_dfs(int now, int num) {
	int ret = 0;
	vst[now] = num;
	if (vst[a[now]] != num) ret += s_dfs(a[now], num);
	for (int nxt : b[now]) if (vst[nxt] != num) {
		ret += s_dfs(nxt, num);
	}
	return ret + 1;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		a[i] = x;
		b[x].push_back(i);
	}

	int num = 0;
	for (int i = 1; i <= n; i++) if (!vst[i]) {
		num++;
		cyc[num] = c_dfs(i, 1, num);
		scc[num] = s_dfs(i, num + 1e9);
	}

	dp[0] = 1;
	for (int i = 1; i <= num; i++)
		for (int j = k; j >= 0; j--)
			for (int p = cyc[i]; p <= scc[i]; p++)
				if (j - p >= 0) dp[j] |= dp[j - p];

	for (int i = k; i >= 0; i--) if (dp[i]) {
		printf("%d\n", i);
		break;
	}

	return 0;
}