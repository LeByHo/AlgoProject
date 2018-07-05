#include <cstdlib> 
#include <cstdio> 
#include <queue> 
#include <utility> 
#include <algorithm>
using namespace std;

bool visited[100001];

int main() {
	int A, B, start, goal;
	scanf("%d %d %d %d", &A, &B, &start, &goal);
	queue< pair<int, int> > que; // position,steps
	que.push(make_pair(start, 0));
	visited[start] = 1;
	while (!que.empty()) {
		pair<int, int> p = que.front(); que.pop();
		int cur = p.first, cnt = p.second;
		if (cur == goal) {
			printf("%d\n", cnt);
			break;
		}
		int move[8] = { -1,1,-A,A,-B,B,cur*A,cur*B };
		for (int i = 0; i < 8; i++) {
			int npos;
			if (i >= 0 && i <= 5) npos = cur + move[i];
			else npos = move[i];
			if (npos >= 0 && npos <= 100000 && !visited[npos]) {
				visited[npos] = 1;
				que.push(make_pair(npos, cnt + 1));
			}
		}
	}
	return 0;
}


