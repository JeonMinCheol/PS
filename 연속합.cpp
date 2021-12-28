#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<int>v;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		v.push_back(c);
	}

	
	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
	}

	vector<int>mi;
	mi.push_back(0);
	int small = v[0];
	for (int i = 0; i < n-1; i++) {
		if (small > v[i]) small = v[i];
		mi.push_back(small);
	}
	
	int result = v[0];
	for (int i = 0; i < n; i++) {
		if (mi[i] < 0) {
			result = max(result, v[i] - mi[i]);
		}
		else {
			result = max(result, v[i]);
		}
	}
	cout << result;
}