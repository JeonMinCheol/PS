#include<iostream>
#include<vector>

using namespace std;

vector<int>mountain;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mountain.push_back(x);
	}

	vector<int> cnt;
	cnt.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mountain[i] > mountain[j]) cnt[i]++;
			else break;
		}
	}

	int max = 0;
	for (auto elem : cnt) {
		if (max < elem) max = elem;
	}
	cout << max;
	return 0;
}