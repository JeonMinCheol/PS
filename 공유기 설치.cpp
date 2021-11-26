#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, c;

int b_search(vector<int>v,int start, int end) {
	int result = 0;
	while (start <= end) {
		stack<int>st;
		int mid = (start + end) / 2;

		st.push(v[0]);
		for (int i = 0; i < n; i++) {
			if (v[i] - st.top() >= mid) {
				st.push(v[i]);
			}
		}

		if (st.size() < c) end = mid - 1;
		else {
			result = mid;
			start = mid + 1;
		}
	}
	return result;
}
int main() {
	cin >> n >> c;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int big = *(--v.end());
	cout << b_search(v, 0, big);
	return 0;
}