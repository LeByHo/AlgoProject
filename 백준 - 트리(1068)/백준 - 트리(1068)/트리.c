#include<stdio.h>

int graph[50][50];
int parent[50];
int del,N,total=0;
void check(int);
int main() {
	int p,root;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p);
		if (p == -1)
			root = i;
		else
			parent[i] = p;
			graph[p][i] = 1;
	}
	scanf("%d", &del);
	for (int i = 0; i < N; i++) {
		graph[del][i] = 0;
	}
	graph[parent[del]][del] = 0;
	if (del == root)
		printf("0");
	else {
		check(root);
		printf("%d", total);
	}
	return 0;
}
void check(int head) {
	int count = 0;
	if (head == del);
	else {
		for (int i = 0; i < N; i++) {
			if (graph[head][i] == 1)
				check(i);
			else
				count++;
		}
		if (count == N)
			total += 1;
	}
}