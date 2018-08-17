#include<iostream>
#include<queue>
#include<cstdio>
#include<utility>

#define P pair<int,int>
#define MP(a,b) make_pair(a,b)
using namespace std;

int totalcnt;
char MAP[12][6];
int check[12][6];    // 0 : ¹æ¹® ¾ÈÇÔ, 1 : »Ñ¼Å¾ßµÊ, 2 : »Ñ½Ç ÇÊ¿ä ¾øÀ½.
char temp[12];
int replay;
int xx[] = { -1,1,0,0 };
int yy[] = { 0,0,-1,1 };

void bfs(int x, int y) {
	int cnt = 0;

	queue<P> Q;
	queue<P> SQ;
	Q.push(MP(x, y));
	SQ.push(MP(x, y));

	char color = MAP[x][y];
	check[x][y] = true;
	cnt++;

	while (!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + xx[i];
			int ny = cy + yy[i];
			if (nx < 0 || ny < 0 || nx >11 || ny >5) continue;    
			if (check[nx][ny]) continue;    
			if (MAP[nx][ny] == color) {    
				cnt++;    
				check[nx][ny] = true;    
				Q.push(MP(nx, ny));
				SQ.push(MP(nx, ny));
			}
		}
	}

	if (cnt < 4) {
		while (!SQ.empty()) {
			check[SQ.front().first][SQ.front().second] = 2;
			SQ.pop();
		}
		return;    
	}
	else replay = 1;    
}

void init_check(void) {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			check[i][j] = 0;
}


void REMAP() {
	for (int i = 0; i < 6; i++) {
		int idx = 11;
		for (int j = 11; j >= 0; j--) {
			if (check[j][i] == 2)
				temp[idx--] = MAP[j][i];
			else if (check[j][i] == 0) break;
		}
		while (idx >= 0) temp[idx--] = '.';
		for (int k = 0; k < 12; k++)
			MAP[k][i] = temp[k];
	}
}


int main() {


	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%c", &MAP[i][j]);
		}
		scanf("%*c");
	}

	while (replay != 2) {
		replay = 0;
		init_check();
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (MAP[i][j] != '.' && check[i][j] == 0) {
					bfs(i, j);  
				}
			}
		}
		REMAP();
		if (replay == 1) totalcnt++;    
		else if (replay == 0) replay = 2;    
	}
	printf("%d\n", totalcnt);
	return 0;
}

