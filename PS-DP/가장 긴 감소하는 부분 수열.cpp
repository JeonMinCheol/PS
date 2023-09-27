#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int inp[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	reverse(inp, inp + n);
	vector<int>v;
	v.push_back(inp[0]);

	for (int i = 1; i < n; i++) {
		if (lower_bound(v.begin(), v.end(), inp[i]) == v.end()) v.push_back(inp[i]);
		else if (upper_bound(v.begin(), v.end(), inp[i]) - lower_bound(v.begin(), v.end(), inp[i]) == 0)* lower_bound(v.begin(), v.end(), inp[i]) = inp[i];
	}
	cout << v.size();

}