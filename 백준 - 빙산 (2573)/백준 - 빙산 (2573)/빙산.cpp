#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pos;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dr[4] = { 0,-1,0,1 };
int dc[4] = { -1,0,1,0 };
int N, M;

void dfs(pos cur) {//��ǥ�� �޾Ƽ�
	visited[cur.first][cur.second] = true;
	//�湮 üũ
	for (int i = 0; i < 4; i++) {//4�� Ž��
		pos next = { cur.first + dr[i],cur.second + dc[i] };
		if (map[next.first][next.second] && !visited[next.first][next.second]) {
			//������ �̾����ְ�, �湮���� �ʾҴٸ�
			dfs(next);//Ž��
		}
	}
}

bool haveIceberg(void) {
	//������ ���� �ִ��� üũ
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c]) return true;
			//�ִٸ� return true;
		}
	}
	return false;//Ž���ϰ� ���ٸ� return false;
}

void melt(void) {
	//���� �������� ������ ��Ƽ� üũ�Ϸ���
	//0�̵Ǽ� �ٴٰ��Ǹ� �ֺ����꿡 ������ �ֱ⿡
	//�ٸ� ������ ������
	vector<vector<int>> melted = map;//map���
	for (int r = 1; r < N; r++) {
		for (int c = 1; c < M; c++) {
			if (map[r][c]) {//���� ������ ������ �ִٸ�
				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					if (!map[r + dr[i]][c + dc[i]]) cnt++;
					//�ֺ��� �ٴ� ������ ����
				}
				melted[r][c] -= cnt;//�����⵵ ������ ǥ��
				if (melted[r][c] < 0) melted[r][c] = 0;
				//-���̶�� 0���� ����
			}
		}
	}
	map = melted;//�ϼ��� �����⵵ ������ �׷���
}

int icebergCnt(void) {
	int year = 0;
	while (true) {
		int iceberg = 0;
		for (int r = 1; r < N; r++) {
			for (int c = 1; c < M; c++) {
				if (map[r][c] && !visited[r][c]) {
					//������ �ִٸ�
					iceberg++;//���� ����++
					dfs(pos(r, c));//Ž��
				}
			}
		}
		if (iceberg > 1) return year;
		//2���� �ɰ����� ��� �������� return
		melt();//�׷��� ������ ������ ��ƿ�
		for (int r = 1; r < N; r++) {
			for (int c = 1; c < M; c++) {
				//�ٽ� Ž���ϱ����� �湮üũ �ʱ�ȭ
				visited[r][c] = false;
			}
		}
		if (!haveIceberg()) return 0;//�ٳ�Ҵٸ� return 0;
		year++;//����++
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
