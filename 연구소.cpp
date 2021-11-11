#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

/*
* 지금 맵에 1이 들어갈 수 있는 모든 경우의 수를 구해야 한다.
* 
*/
int n, m, result = 3;
bool check[9][9] = { false, };
bool chk[9][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0 ,1,-1 };
vector<vector<int>>map;
vector<vector<int>>simulation;
vector<pair<int, int>>virus_location;

int virus(vector<vector<int>>& map , int row , int col) { // 바이러스를 퍼트리는 함수, 그냥 BFS
	int cnt = 0;
	copy(&check[0][0], &check[0][0] + 81, &chk[0][0]); // 배열이 그냥 복사가 안되므로 이런식으로 algorithm안에 내장된 함수를 써야 한다.
	queue<pair<int, int>>q;
	q.push({ col,row });
	
	while (!q.empty()) {
		int x = q.front().first; // col
		int y = q.front().second; // row
		chk[y][x] = true;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x; // col
			int ny = dy[i] + y; // row

			if (nx < 0 || ny < 0 || m <= nx || n <= ny) continue;
			else if (chk[ny][nx]) continue;
			q.push({ nx,ny });
		}
	}
	return max(result, n*m - cnt);
}  

int first_x = 0, first_y = 0;
int second_x = 1, second_y = 1;
int third_x = 2, third_y = 2;

int main() {
	cin >> n >> m;
	map.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			map[i].push_back(x);
			if (x == 1) check[i][j] = true;
			else if (x == 2) {
				virus_location.push_back({ i,j });
				check[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int elem = simulation[i][j];
			if (elem == 2) result = virus(map, i, j);
		}
	}
	while (!(first_x == n - 3 && first_y == m - 3 && second_x == n - 2 && second_y == m - 2 && third_x == n - 1 && third_y == m - 1)) {
		 
		simulation[first_x][first_y] = 1;
		simulation[second_x][second_y] = 1;
		simulation[third_x][third_y] = 1;
		third_x++;
		second_x++;
	 }
}