#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef stack<int> SI;

VVI G;
VVI RG;
VVI ans;
VI vInfoAns;
VB vis;
SI st;
int noV, noE, noAns;

void dfs(int vertex) {
	for (auto iter = G[vertex].begin(); iter != G[vertex].end(); iter++) {
		int here = *iter;

		if (!vis[here]) {
			vis[here] = true;
			dfs(here);
			st.push(here);
		}

	}
	return;
}

void dfsReverse(int vertex) {
	for (auto iter = RG[vertex].begin(); iter != RG[vertex].end(); iter++) {
		int here = *iter;

		if (!vis[here]) {
			vis[here] = true;
			vInfoAns[here] = noAns;
			dfsReverse(here);
			ans[noAns].push_back(here);
		}
	}
	return;
}

int main() {

	scanf("%d%d", &noV, &noE);

	G = VVI(noV + 1, VI(0, 0));
	RG = VVI(noV + 1, VI(0, 0));
	ans = VVI(noV + 1, VI(0, 0));
	vis = VB(noV + 1, false);

	for (int i = 0; i < noE; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		RG[v].push_back(u);
	} // input data

	for (int i = 1; i <= noV; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(i);
			st.push(i);
		}
	} // vertex sequence 

	vis = VB(noV + 1, false);
	vInfoAns = VI(noV + 1, -1);
	while (!st.empty()) {
		int here = st.top(); st.pop();

		if (!vis[here]) {
			vis[here] = true;
			ans[noAns].push_back(here);
			vInfoAns[here] = noAns;
			dfsReverse(here);
			noAns++;
			sort(ans[noAns - 1].begin(), ans[noAns - 1].end());
		}
	} // vertex SCC

	vis = VB(noAns + 1, false);
	printf("%d\n", noAns);
	for (int i = 1; i <= noV; i++) {
		int here = vInfoAns[i]; // == noAns
		if (!vis[here]) {
			vis[here] = true;
			for (auto iter = ans[here].begin(); iter != ans[here].end(); iter++) {
				printf("%d ", *iter);
			}
			puts("-1");
		}
	}

	return 0;
}