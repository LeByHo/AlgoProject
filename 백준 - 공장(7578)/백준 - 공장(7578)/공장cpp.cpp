#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int tree[500002];
int n;

void update(int i)
{
	while (i <= n)
	{
		tree[i] += 1;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);

	vector<int> vcA;
	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);

		vcA.push_back(val);
	}

	map<int, int> B;
	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);

		B[val] = i;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int valA = vcA[i];
		int idxB = B[valA];

		ans += (ll)sum(n) - (ll)sum(idxB);

		update(idxB);
	}

	printf("%lld", ans);

	return 0;
}


