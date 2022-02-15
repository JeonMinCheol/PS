#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, s, m;
int music[50];
bool check[50][1001];
int main() {
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> music[i];
	}
	vector<vector<int>>v(n+1);
	v[0].push_back(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] - music[i] >= 0 && !check[i][v[i][j] - music[i]]) {
				v[i + 1].push_back(v[i][j] - music[i]);
				check[i][v[i][j] - music[i]] = true;
			}
			if (v[i][j] + music[i] <= m && !check[i][v[i][j] + music[i]]) {
				v[i + 1].push_back(v[i][j] + music[i]);
				check[i][v[i][j] + music[i]] = true;
			}
		}
	}

	if (v[n].empty()) {
		cout << -1;
		return 0;
	}
	sort(v[n].begin(), v[n].end());
	cout << *(--v[n].end());
}