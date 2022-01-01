#include<iostream>
#include<vector>
using namespace std;

int n, m;
long long int result = 0;
int dx[3] = { -1,-1,0 };
int dy[3] = { -1,0,-1 };
int main() {
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				
				if (ni < 0 || nj < 0) continue;
				sum = max(v[ni][nj], sum);
			}
			v[i][j] += sum;
		}
	}

	cout << v[n - 1][m - 1];
}