#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int u, v;
vector<vector<int>>graph;
bool chk[1001] = { false ,};
int bfs(int n) {
	if (chk[n]) return 0;
	queue<int>q;
	q.push(n);

	while (!q.empty()) {
		int f = q.front();
		chk[f] = true;
		q.pop();

		for (int i = 0; i < graph[f].size(); i++) {
			int elem = graph[f][i];
			if (!chk[elem]) {
				chk[elem] = true;
				q.push(elem);
			}
		}
	}

	return 1;
}
int main() {
	cin >> n >> m;
	graph.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if(!chk[i]) result += bfs(i);
	}
	cout << result;
	return 0;
}