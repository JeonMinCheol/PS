#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int search(vector<int>&v) {
	vector<int>temp;
	temp.push_back(v[0]);

	for (int i = 1; i < n; i++) {
		int start = 0, end = temp.size();
		while (start < end) {
			int mid = (start + end) / 2;
			if (temp[mid] >= v[i]) end = mid;
			else start = mid + 1;
		}
		if (end == temp.size()) temp.push_back(v[i]);
		else temp[end] = v[i];
	}
	
	return temp.size();
}
int main() {
	while (cin >> n) {
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << search(v)<<"\n";

	}
}