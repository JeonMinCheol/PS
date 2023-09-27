#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n;
int dist[126][126];
int map[126][126];
bool visit[126][126] = {false};
int dx[4] = { 1, -1 ,0, 0 };
int dy[4] = { 0,0,1,-1 };

pair<int,int> get_smallest_node() {
	int cost = INF;
	pair<int,int> index = {0,0};
	for (int i = 0; i < n; i++) {
		for(int j=0; j<n; j++) if (!visit[i][j] && cost > dist[i][j]) cost = dist[i][j], index = {i,j};
	}
	return index;
}

int stra() {
	visit[0][0] = true;
	dist[0][0] = map[0][0];
	pair<int, int> here = {0,0};
	for (int i = 0; i < 4; i++) {
		if (here.first + dx[i] < 0 || here.second + dy[i] < 0 || here.first + dx[i] >= n || here.second + dy[i] >= n) continue;
		dist[here.first + dx[i]][here.second + dy[i]] = map[here.first + dx[i]][here.second + dy[i]] + dist[0][0];
	}

	while (true) {
		here = get_smallest_node();
		if (here.first == 0 && here.second == 0) break;
		visit[here.first][here.second] = true;
		for (int i = 0; i < 4; i++) {
			if (here.first + dx[i] < 0 || here.second + dy[i] < 0 || here.first + dx[i] >= n || here.second + dy[i] >= n) continue;
			if (dist[here.first + dx[i]][here.second + dy[i]] > dist[here.first][here.second] + map[here.first + dx[i]][here.second + dy[i]])
				dist[here.first + dx[i]][here.second + dy[i]] = dist[here.first][here.second] + map[here.first + dx[i]][here.second + dy[i]];
		}
	}

	return dist[n-1][n-1];
}
int main() {
	int cnt = 0;
	while (cin >> n) {
		if (n == 0) break;
		fill_n(&dist[0][0], 126 * 126, INF);
		fill_n(&visit[0][0], 126 * 126, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		
		cout << "Problem " << ++cnt<<": "<< stra()<<endl;
	}
	
}