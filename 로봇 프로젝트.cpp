#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, x;

void search(vector<int>& v) {
	for (int i = n - 1; i > 0; i--) {
		int start = 0, end = i - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (v[i] + v[mid] < x) start = mid + 1;
			else if (v[i] + v[mid] > x) end = mid - 1;
			else {
				cout << "yes " << v[mid] << " " << v[i] << endl;
				return;
			}
		}
	}
	cout << "danger";

}

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	while (cin >> x >> n) {
		x *= 10000000;
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		search(v);
	}

}