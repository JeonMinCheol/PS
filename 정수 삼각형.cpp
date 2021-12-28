#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>>v(n);
	for (int i = 0; i < n; i++) {
		vector<int>temp;
		for (int j = 0; j < i + 1; j++) {
			int c;
			cin >> c;
			temp.push_back(c);
		}
		v[i] = temp;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) v[i][j] += v[i - 1][0];
			else if (j == i) v[i][j] += v[i - 1][i - 1];
			else {
				v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
			}
		}
	}
	sort(v[n - 1].begin(), v[n - 1].end());
	cout << v[n - 1][n - 1];
}