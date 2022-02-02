#include<iostream>
using namespace std;

int	n, m;
int a, s, d, f;
int sum[1001][1001] = {0};
int cs[100001][4];


int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			sum[i][j] = sum[i][j - 1] + sum[i-1][j] + x - sum[i-1][j-1];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> cs[i][0] >> cs[i][1] >> cs[i][2] >> cs[i][3];
	}
	
	for (int i = 0; i < m; i++) {
		int y1 = cs[i][0], x1 = cs[i][1], y2 = cs[i][2], x2 = cs[i][3];

		long long int result = sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1];
		cout << result << "\n";
	}
	return 0;
}