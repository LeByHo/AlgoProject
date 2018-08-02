#include <cstdio>
#include <vector>
using namespace std;

int N, M, ans = 0;
int person[1001], task[1001];
vector<int> v[1001];
bool visited[1001];

bool dfs(int start) {
	visited[start] = 1;
	for (auto n : v[start]) {
		if (task[n] == -1 || (!visited[task[n]] && dfs(task[n]))) {
			person[start] = n;
			task[n] = start;
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
	fill(person, person + N, -1);
	fill(task, task + M, -1);
	for (int i = 0; i < N; i++) {
		if (person[i] == -1) {
			fill(visited, visited + N, false);
			if (dfs(i))
				ans++;
		}
	}
	printf("%d", ans);
}