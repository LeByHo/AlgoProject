#include <iostream>
#include <queue>
using namespace std;
int T, a, b;
int num[9000];

bool enable_q(int now) {
	bool chk = true;
	for (int i = 2; i<now; i++) {
		if (!(now%i)) {
			chk = false;
			break;
		}
	}
	return chk;
}
void bfs(int start) {
	queue<int> q;
	q.push(start);

	num[start - 1000] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int j = 0; j<10; j++) {
			int next[4];

			next[0] = (now % 1000) + j * 1000;
			next[1] = now - ((now % 1000) / 100) * 100 + j * 100;
			next[2] = now - ((now % 100) / 10) * 10 + j * 10;
			next[3] = (now / 10) * 10 + j;

			for (int i = 0; i<4; i++) {
				if (next[i]>999 && next[i]<10000 && enable_q(next[i]) && !num[next[i] - 1000]) {
					q.push(next[i]);
					num[next[i] - 1000] = num[now - 1000] + 1;
				}
			}

		}
	}
}

int main() {
	cin >> T;
	while (T-->0) {
		cin >> a >> b;
		for (int i = 0; i<9000; i++)
			num[i] = 0;
		bfs(a);
		if (num[b - 1000]>0) cout << num[b - 1000] - 1 << endl;
		else cout << "Impossible" << endl;
	}
}
