#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int solve(vector<pair<int, int>>&v) {
	vector<int>temp;
	temp.push_back(v[0].second);

	for (int i = 1; i < n; i++) {
		if (upper_bound(temp.begin(), temp.end(), v[i].second) - temp.end() != 0) *(lower_bound(temp.begin(), temp.end(), v[i].second)) = v[i].second;
		else temp.push_back(v[i].second);
	}

	return n - temp.size();
}
int main() {
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		pair<int, int>p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end());

	cout << solve(v);
}