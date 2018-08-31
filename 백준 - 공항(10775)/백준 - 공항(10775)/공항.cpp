#include <cstdio>

#include <algorithm>

#include <set>

using namespace std;

int    N, M;

set<int> v;

int main() {

	scanf("%d%d", &M, &N);

	for (int m = 1; m <= M; m++)

		v.insert(-m);



	int ans = 0;

	bool f = false;

	for (int n = 0; n < N; n++) {

		int u;

		scanf("%d", &u);

		auto get = v.lower_bound(-u);

		if (get == v.end()) break;

		v.erase(get);

		ans++;

	}

	printf("%d\n", ans);

	return 0;

}