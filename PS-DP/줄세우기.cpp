#include<iostream>
#include<vector>
using namespace std;

int n;
int kids[201];
int lower(int kid, vector<int>& lis) {
	int left = 0, right = lis.size(), mid, result = lis.size();
	while (left < right) {
		mid = (left + right) / 2;
		if (kid <= lis[mid]) {
			right = mid;
			result = mid;
		}
		else if (lis[mid] < kid) left = mid + 1;
	}
	return result;
}


int solve() {
	vector<int>lis;
	lis.push_back(kids[1]);
	for (int i = 2; i <= n; i++) {
		int kid = kids[i];

		if (lower(kid, lis) < lis.size()) lis[lower(kid, lis)] = kid;
		else lis.push_back(kid);
	}
	return n - lis.size();
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> kids[i];
	}
	cout << solve();
}