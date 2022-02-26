#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

#define MAX 1e9
using namespace std;


int n, m, c;
int dist[30001];
void dijk(vector<vector<pair<int, int>>>&v) {
	priority_queue<pair<int, int>>q;
	dist[c] = 0;
	q.push(make_pair(0, c));

	while (!q.empty()) {
		int cost = -q.top().first;
		int here = q.top().second;
		q.pop();

		for (int i = 0; i < v[here].size(); i++) {
			int weight = v[here][i].second;
			int there = v[here][i].first;

			if (dist[there] < cost + weight) continue;
			dist[there] = cost + weight;
			q.push(make_pair(-dist[there], there));
		}
	}
}
int main() {
	cin >> n >> m >> c;
	fill_n(dist, 30001, MAX);

	vector<vector<pair<int, int>>>v(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
	}
	
	dijk(v);
	int ret[2] = { 0, 0 };
	for (int i = 1; i < n; i++) {
		if (dist[i] < MAX) ret[0] += 1, ret[1] += dist[i];
	}
	cout << ret[0] << " " << ret[1];
	
	return 0;
}