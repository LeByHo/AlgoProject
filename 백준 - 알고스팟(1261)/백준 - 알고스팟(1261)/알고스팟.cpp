#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#define INF 99999999;
using namespace std;

const int MAX = 100;
typedef pair<int, int> pii;

int main() {
	int M, N, table[MAX + 1][MAX + 1] = { 0 }, dis[MAX + 1][MAX + 1] = { 0 };
	priority_queue <pii, vector<pii>, greater<pii>> PQ;

	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &table[i][j]);
			dis[i][j] = INF;
		}
	}

	PQ.push(pii(0, 0));
	dis[0][0] = 0;
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };
	while (!PQ.empty()) {
		pii cur = PQ.top(); PQ.pop();
		int w = cur.first;
		int x = cur.second / MAX;
		int y = cur.second%MAX;
		if (w>dis[y][x])continue;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x<0 || next_y<0 || next_x >= M || next_y >= N)continue;

			if (dis[next_y][next_x]>table[next_y][next_x] + dis[y][x]) {
				dis[next_y][next_x] = table[next_y][next_x] + dis[y][x];
				PQ.push(pii(dis[next_y][next_x], next_x*MAX + next_y));
			}
		}
	}

	printf("%d", dis[N - 1][M - 1]);

}
