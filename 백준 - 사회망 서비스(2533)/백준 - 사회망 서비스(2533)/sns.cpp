#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring> //memset;

using namespace std;

const int MAX = 1000000 + 1;
int N;
vector<int> friends[MAX]; //ó�� �Է��ϴ� ģ�� ����
vector<int> dirNode[MAX]; //�ܹ��� �׷��� ����
bool visited[MAX];
int cache[MAX][2]; //���, earlyAdaptor?

void DFS(int nodeNum)
{
	visited[nodeNum] = true;
	for (int i = 0; i < friends[nodeNum].size(); i++)
	{
		int next = friends[nodeNum][i];
		if (!visited[next])
		{
			dirNode[nodeNum].push_back(next);
			DFS(next);
		}
	}
}

int getEarlyAdaptor(int nodeNum, bool early)
{
	int &result = cache[nodeNum][early];
	if (result != -1)
		return result;
	if (early)
	{
		result = 1; //�󸮾�����̹Ƿ�
		for (int i = 0; i < dirNode[nodeNum].size(); i++)
		{
			int next = dirNode[nodeNum][i];
			result += min(getEarlyAdaptor(next, true), getEarlyAdaptor(next, false));
		}
	}
	//������ �󸮾���Ͱ� �ƴϸ� �ڽ��� ������ �󸮾���Ϳ����Ѵ�
	else
	{
		result = 0; //�󸮾���Ͱ� �ƴϹǷ�
		for (int i = 0; i < dirNode[nodeNum].size(); i++)
		{
			int next = dirNode[nodeNum][i];
			result += getEarlyAdaptor(next, true);
		}
	}

	return result;

}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		friends[node1].push_back(node2);
		friends[node2].push_back(node1);
	}
	memset(cache, -1, sizeof(cache));
	DFS(1); //1�� ��Ʈ
	printf("%d", min(getEarlyAdaptor(1, false), getEarlyAdaptor(1, true)));
	return 0;
}