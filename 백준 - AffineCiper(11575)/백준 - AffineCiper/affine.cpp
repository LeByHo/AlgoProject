#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#include <string.h>

int main() {
	int t, a, b, i, j, length = 0, X = 0;
	char str[1000000] = " ";
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		scanf("%s", str);

		length = strlen(str);

		for (j = 0; j < length; j++) {

			X = str[j] - 65;

			str[j] = ((a * X + b) % 26) + 65;

		}

		printf("%s\n", str);
	}
}