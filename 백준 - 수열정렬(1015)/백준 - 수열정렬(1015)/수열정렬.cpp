#include <cstdio>
#include <algorithm>
using namespace std;
int n, i, b[55];
pair<int, int> a[55];
int main() {
	scanf("%d", &n);
	while (i < n) scanf("%d", &a[i].first), a[i].second = i, i++;
	sort(a, a + n);
	while (i--) b[a[i].second] = i;
	i++;
	while (i < n) printf("%d ", b[i++]);
	return 0;
}