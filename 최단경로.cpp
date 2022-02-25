#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1e9

int V, E, K;
int dist[20001];
void dijk(int start , vector<vector<pair<int, int>>>&vp) {
	priority_queue<pair<int, int>>pq;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		//���� �������� �ִܰŸ�, ���
		int distance = -pq.top().first, node = pq.top().second;
		int weight , there;
		pq.pop();

		for (auto elem : vp[node]) {
			//��������� �Ÿ� + ����ġ, ���� ���� ���� ����� ���
			weight = distance + elem.first;
			there = elem.second;

			//�ִܰŸ����� �۾ƾ� ť�� �ִ´�.
			if (dist[there] < weight) continue;
			pq.push({ -weight,there });
			dist[there] = weight;
		}
	}
}
int main() {
	cin >> V >> E >> K;
	// u���� v�� ���� ����ġ w�� ���� (����ġ , ����)
	vector<vector<pair<int, int>>>vp(V+1);
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vp[u].push_back({ w,v });
	}

	fill_n(dist, 20001, MAX);
	dijk(K , vp);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == MAX) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}