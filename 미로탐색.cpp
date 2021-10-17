#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[25][25];
vector<int>house;
int cnt = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1, };

void dfs(int x, int y) {
	cnt++;
	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < n) {
			if(map[x + dx[i]][y + dy[i]] == 1) dfs(x + dx[i] , y + dy[i]);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;

			map[i][j] = int(c) - 48;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				house.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(house.begin(), house.end());
	cout << house.size()<<endl;
	for (auto elem : house) {
		cout << elem<<endl;
	}
}