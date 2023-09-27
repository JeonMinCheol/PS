#include<iostream>
#include<cstring>
#include<vector>
#define INF 1e9
using namespace std;

int n, e, v1, v2;;
int dist[801];
bool visit[801] = {0};
int get_smallest_node() {
	int small = INF , ret = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && small > dist[i]) small = dist[i] , ret = i;
	}
	return ret;
}

void dijk(int start ,vector < vector<pair<int, int>>>&vp) {
	dist[start] = 0;

	int here, cost;
	while (true) {
		here = get_smallest_node();
		cost = dist[here];
		visit[here] = true;
		if (here == 0) break;
	
		for (int i = 0; i < vp[here].size(); i++) {
			int there = vp[here][i].first, there_cost = vp[here][i].second;
			if (!visit[there] && dist[there] > there_cost + cost) dist[there] = there_cost + cost;
		}
	}
	return ;
}
int main() {
	cin >> n >> e;
	vector < vector<pair<int, int>>>vp(n+1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vp[a].push_back(make_pair(b, c));
		vp[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	int way[3] = { 1,v1,v2 };
	int cost[4][2] = {
		{-1,-1} ,
		{} ,
		{} ,
		{}
	};
	for (int i = 1; i <=3; i++) {
		fill_n(dist, 801, INF);
		fill_n(visit, 801, false);
		dijk(way[i - 1], vp);
		if (i == 1) cost[1][0] = dist[v1], cost[1][1] = dist[v2];
		else if (i == 2) cost[2][0] = dist[v2], cost[2][1] = dist[n];
		else if(i == 3) cost[3][0] = dist[v1], cost[3][1] = dist[n];
	}

	int ret = min(cost[1][1] + cost[3][0] + cost[2][1],cost[1][0] + cost[2][0] + cost[3][1]);
	if (ret >= INF || ret < 0) cout << -1;
	else cout << ret;
}
