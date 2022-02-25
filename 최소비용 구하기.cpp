#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 1e9

int N, M, start, en;
int dist[1001];
bool visit[1001];

int shortest() {
	int m = MAX, index = 0;
	for (int i = 1; i <= N; i++) {
		if (m > dist[i] && !visit[i]) m = dist[i], index = i;
	}
	return index;
}

void dijk(int start, vector<vector<pair<int, int>>>& vp) {
	dist[start] = 0;
	visit[start] = true;

	int closest = MAX;
	int here = start;
	//기준 노드와 붙어있는 노드들 거리 최신화
	for (int i = 0; i < vp[start].size(); i++) {
		dist[vp[start][i].second] = min(dist[vp[start][i].second], vp[start][i].first);
		if (closest > dist[vp[start][i].second]) closest = dist[vp[start][i].second];
	}

	while (true) {
		here = shortest();
		if (here == 0) break;
		//기준 노드와 붙어있는 노드들 거리 최신화
		for (int i = 0; i < vp[here].size(); i++) {
			if (!visit[vp[here][i].second]) dist[vp[here][i].second] = min(dist[vp[here][i].second], vp[here][i].first + dist[here]);
		}
		visit[here] = true;
	}
}
int main() {
	cin >> N >> M;
	vector<vector<pair<int, int>>>vp(N + 1);
	fill_n(dist, 1001, MAX);
	fill_n(visit, 1001, false);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vp[a].push_back({ c,b });
	}
	cin >> start >> en;
	dijk(start, vp);
	cout << dist[en];

	return 0;
}