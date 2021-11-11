#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m, result = -1 , cnt;
int map[8][8];
int check[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0 ,1,-1 };

vector<pair<int, int>>virus_location;
vector<pair<int, int>>zero_location;

int virus(int row , int col) { // 바이러스를 퍼트리는 함수, 그냥 BFS
	cnt = 0;
	queue<pair<int, int>>q;
	q.push({ col,row });
	while (!q.empty()) {
		int x = q.front().first; // col
		int y = q.front().second; // row
		check[y][x] = 2;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x; // col
			int ny = dy[i] + y; // row

			if (nx < 0 || ny < 0 || m <= nx || n <= ny) continue;
			else if (check[ny][nx] != 0) continue;
			q.push({ nx,ny });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) cnt++;
		}
	}
	return cnt;
}  



int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 2) virus_location.push_back({ i,j });
			else if(map[i][j] == 0) zero_location.push_back({ i,j });
		}
	}

	int size = zero_location.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				copy(&map[0][0], &map[0][0] + 64, &check[0][0]); // 배열이 그냥 복사가 안되므로 이런식으로 algorithm안에 내장된 함수를 써야 한다.

				check[zero_location[i].first][zero_location[i].second] = 1;
				check[zero_location[j].first][zero_location[j].second] = 1;
				check[zero_location[k].first][zero_location[k].second] = 1;
				int virus_size = virus_location.size();

				for (int a = 0; a < virus_size; a++) {
					if (a == virus_size - 1) {
						result = max(result, virus(virus_location[a].first, virus_location[a].second));
						break;
					}
					virus(virus_location[a].first, virus_location[a].second);
				}
				
			}
		}
	}
	
	cout << result;
}