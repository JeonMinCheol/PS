#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, m;

int b_search(vector<int>v,int start, int end) {
	int result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] <= mid) cnt += v[i];
			else cnt += mid;
		}

		if (cnt <= m) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return result;
}
int main() {
	cin >> n;
	vector<int>v(n);
	int big = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (big < v[i]) big = v[i];
	}

	cin >> m;
	cout << b_search(v, 0, big);


	return 0;
}