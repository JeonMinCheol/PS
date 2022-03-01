#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, x;
int dist1[1001] , dist2[1001];
void stra(vector<vector<pair<int, int>>>& map, int* dist) {
	priority_queue<pair<int, int>>q;
	dist[x] = 0;
	q.push({ 0, x });

	while (!q.empty()) {
		int here = q.top().second;
		int cost = -q.top().first;
		q.pop();

		for (int i = 0; i < map[here].size(); i++) {
			int there = map[here][i].first;
			int there_cost = map[here][i].second;

			if (dist[there] > there_cost + cost) {
				dist[there] = there_cost + cost;
				q.push({-dist[there], there});
			}
		}
	}
}
int main() {
	cin >> n >> m >> x;
	fill_n(dist1, 1001, INF), fill_n(dist2, 1001, INF);
	vector<vector<pair<int, int>>>map1(n+1);
	vector<vector<pair<int, int>>>map2(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map1[a].push_back(make_pair(b, c));
		map2[b].push_back(make_pair(a, c));
	}

	stra(map1, dist1), stra(map2, dist2);

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, dist1[i] + dist2[i]);
	}
	cout << ret;
}