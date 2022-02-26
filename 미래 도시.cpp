#include<iostream>
#include<cstring>

#define INF 1e9
using namespace std;

int n, m, x, k;
int dist[101][101];
int floyd_warshall() {
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
			}
		}
	}
	if (dist[k][x] == INF || dist[1][k] == INF) return -1;
	return dist[1][k] + dist[k][x];
}

int main() {
	cin >> n >> m;
	fill_n(&dist[0][0], 101 * 101, INF);
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	cin >> x >> k;
	cout << floyd_warshall();
}
