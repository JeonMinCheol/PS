#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int tree[100000];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	int day = 0;
	int max = 0;
	sort(tree, tree + n, greater<>());

	for (int i = 0; i < n; i++) {
		day++;
		int temp = day + tree[i] + 1;
		if (max < temp) max = temp;
	}
	cout << max;
	return 0;
}