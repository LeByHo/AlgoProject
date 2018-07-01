#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 9999999999;
int N, C;
int pos[100005];

bool ok(int k)
{
	int cur = pos[0];
	int cnt = 1;
	for (int i = 1; i<N; ++i) {
		if (pos[i] - cur >= k) {
			++cnt;
			cur = pos[i];
		}
	}
	return cnt >= C;

}
int main()
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i<N; ++i)
		scanf("%d", &pos[i]);
	sort(pos, pos + N);
	int l = 1;
	int r = pos[N - 1] - pos[0];
	while (l<r) {
		int mid = (l + r + 1) / 2;
		if (ok(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d",l);
}