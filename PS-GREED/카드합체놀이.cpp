#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int>v;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());
		int k = v[0] + v[1];
		v[0] = k , v[1] = k;
	}
	int result = 0;
	for (auto elem : v) {
		result += elem;
	}
	cout << result;
}