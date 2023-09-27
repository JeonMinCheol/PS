#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int search(vector<int>& v) {
	vector<int>q;
	int cnt = 1;

	q.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		int start = 0, end = q.size();
		while (start < end) {
			int mid = (start + end) / 2;
			if (q[mid] < v[i]) start = mid + 1;
			else end = mid;
		}
		
		if (end == q.size()) {
			q.push_back(v[i]);
		}
		else {
			q[end] = v[i];
		}
	}
	for (auto elem : q) cout << elem << " ";
	cout << "\n";
	return n - q.size();
}

int main() {
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin>>v[i];
	cout << search(v);

	return 0;
}