#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pos;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dr[4] = { 0,-1,0,1 };
int dc[4] = { -1,0,1,0 };
int N, M;

void dfs(pos cur) {//좌표를 받아서
	visited[cur.first][cur.second] = true;
	//방문 체크
	for (int i = 0; i < 4; i++) {//4방 탐색
		pos next = { cur.first + dr[i],cur.second + dc[i] };
		if (map[next.first][next.second] && !visited[next.first][next.second]) {
			//빙산이 이어져있고, 방문하지 않았다면
			dfs(next);//탐색
		}
	}
}

bool haveIceberg(void) {
	//빙산이 남아 있는지 체크
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c]) return true;
			//있다면 return true;
		}
	}
	return false;//탐색하고도 없다면 return false;
}

void melt(void) {
	//원래 지도에서 빙산이 녹아서 체크하려면
	//0이되서 바다가되면 주변빙산에 영향을 주기에
	//다른 지도를 만들어요
	vector<vector<int>> melted = map;//map백업
	for (int r = 1; r < N; r++) {
		for (int c = 1; c < M; c++) {
			if (map[r][c]) {//원래 지도에 빙산이 있다면
				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					if (!map[r + dr[i]][c + dc[i]]) cnt++;
					//주변의 바다 갯수를 세요
				}
				melted[r][c] -= cnt;//다음년도 지도에 표현
				if (melted[r][c] < 0) melted[r][c] = 0;
				//-값이라면 0으로 보정
			}
		}
	}
	map = melted;//완성된 다음년도 지도를 그려요
}

int icebergCnt(void) {
	int year = 0;
	while (true) {
		int iceberg = 0;
		for (int r = 1; r < N; r++) {
			for (int c = 1; c < M; c++) {
				if (map[r][c] && !visited[r][c]) {
					//빙산이 있다면
					iceberg++;//빙산 갯수++
					dfs(pos(r, c));//탐색
				}
			}
		}
		if (iceberg > 1) return year;
		//2개로 쪼개지면 몇년 지났는지 return
		melt();//그렇지 않으면 빙산이 녹아요
		for (int r = 1; r < N; r++) {
			for (int c = 1; c < M; c++) {
				//다시 탐색하기위해 방문체크 초기화
				visited[r][c] = false;
			}
		}
		if (!haveIceberg()) return 0;//다녹았다면 return 0;
		year++;//연도++
	}
}

int main(void) {
	cin >> N >> M;
	map.resize(N);
	visited.resize(N);
	for (int r = 0; r < N; r++) {
		map[r].resize(M);
		visited[r].resize(M);
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}
	cout << icebergCnt() << endl;

	return 0;
}
