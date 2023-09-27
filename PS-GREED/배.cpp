#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>limit , box;
int n, m;

int main() {
	cin >> n;
	limit.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> limit[i];
	}
	sort(limit.begin(), limit.end(), greater<>());

	cin >> m;
	box.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}
	sort(box.begin(), box.end(), greater<>());
	
	if (*box.begin() > *limit.begin()) {
		cout << -1;
		return 0;
	}

	int time = 0;
	while (!box.empty()) {
		for (int i = 0; i < n; i++) {
			if (box.empty() || *(--box.end()) > limit[i]) break;
			int x = limit[i];
			for (auto iter = box.begin(); iter != box.end(); iter++) {
				if (x >= *iter) {
					box.erase(iter);
					break;
				}
				
			}
		}
		time++;
	}
	cout << time;
	return 0;
}