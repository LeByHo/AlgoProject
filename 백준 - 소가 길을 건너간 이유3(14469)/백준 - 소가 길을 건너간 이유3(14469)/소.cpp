#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int>> cow;
int main() {
	int n,arr,time,total=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr, &time);
		cow.push_back(make_pair(arr, time));
	}
	sort(cow.begin(), cow.end());
	total = cow[0].first + cow[0].second;
	for (int i = 1; i < n; i++) {
		if (cow[i].first > total)
			total = cow[i].first;
		total += cow[i].second;
	}
	printf("%d", total);
}