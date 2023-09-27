#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n, m;
int dist[100001];
int stra() {
	priority_queue<pair<int, int>>q;
	dist[n] = 0;
	q.push({ 0, -n });
	while (!q.empty()) {
		int here = -q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (2 * here < 2 * m && 2 * here  < 100001&& dist[2 * here] > cost) {
			dist[2 * here] = cost;
			q.push({ -dist[2 * here] , -2 * here });
		}
		if (here > 0 && dist[here - 1] > cost + 1) {
			dist[here - 1] = cost + 1;
			q.push({ -dist[here - 1] , -here + 1 });
		}
		if (here + 1 < 2 * m && here + 1 < 100001 && dist[here + 1] > cost + 1) {
			dist[here + 1] = cost + 1;
			q.push({ -dist[here + 1] ,-here - 1 });
		}
		if (dist[m] != INF) return dist[m];
	}

	return 0;
}
int main() {
	cin >> n >> m;
	fill_n(dist, 100001, INF);
	cout << stra();
}