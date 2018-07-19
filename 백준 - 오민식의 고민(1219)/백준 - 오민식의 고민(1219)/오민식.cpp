#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>

#define INF 999999999

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll dist[111];
ll cost[111];
bool getGee[111];
vector<pii> adj[111];

bool visit[111];

int main()
{
	int V, E, start, end;
	int cnt = 0;

	scanf("%d %d %d %d", &V, &start, &end, &E);

	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);

		adj[from].push_back({ to, val });
	}

	for (int i = 0; i < V; i++)
		scanf("%lld", &cost[i]);

	for (int i = 0; i < V; i++)
		dist[i] = -INF;

	dist[start] = cost[start];

	// 벨만포드
	bool update = true;
	bool ok = false;
	while (update && cnt != V)
	{
		update = false;

		for (int i = 0; i < V; i++)
			for (auto j : adj[i])
			{
				if (dist[i] != -INF && dist[i] + cost[j.first] - j.second > dist[j.first])
				{
					dist[j.first] = dist[i] + cost[j.first] - j.second;
					update = true;

					if (cnt == V - 1)
						getGee[i] = true;
				}
			}
		cnt++;
	}

	// bfs
	bool getChk = false;
	queue<int> q;

	for (int i = 0; i < V; i++)
		if (getGee[i])
			q.push(i);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (visit[here])
			continue;

		visit[here] = true;

		for (int i = 0; i < adj[here].size(); i++)
		{
			if (adj[here][i].first == end)
			{
				getChk = true;
				break;
			}
			if (!visit[adj[here][i].first])
				q.push(adj[here][i].first);
		}

		if (getChk)
			break;
	}

	if (dist[end] == -INF)
		printf("gg");
	else if (getChk)
		printf("Gee");
	else
		printf("%lld", dist[end]);


	return 0;
}

