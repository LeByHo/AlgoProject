#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int a[50], b[50];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	sort(a,a+n);
	sort(b, b + n, greater<int>());
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i] * b[i];
	}
	printf("%d", total);
	return 0;
}