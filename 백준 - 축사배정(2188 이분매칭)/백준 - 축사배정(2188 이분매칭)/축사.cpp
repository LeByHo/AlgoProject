#include <cstdio>
#include <vector>
using namespace std;

int N, M, ans = 0;
int cow[202], barn[202];
vector<int> v[202];
bool visited[202];

bool dfs(int start) {
	visited[start] = 1;
	for (auto n : v[start]) {
		if (barn[n] == -1 || (!visited[barn[n]] && dfs(barn[n]))) {
			cow[start] = n;
			barn[n] = start;
			return true;
		}
	}
	return false;
}
int main() {
	int a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			v[i].push_back(b - 1);
		}
	}
	fill(cow, cow + N, -1);
	fill(barn, barn + M, -1);
	for (int i = 0; i < N; i++) {
		if (cow[i] == -1) {
			fill(visited, visited + N, false);
			if (dfs(i))
				ans++;
		}
	}
	printf("%d", ans);
}