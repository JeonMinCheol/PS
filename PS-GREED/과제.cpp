#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	vector<pair<int,int>>homework(n);
	int day = 0;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		homework[i] = { w,d };
		if (day < d) day = d;
	}

	sort(homework.begin(), homework.end(), greater<>());
	for (auto h : homework) {
	}
	int result = 0;

	while (day--) {
		for (auto iter = homework.begin(); iter != homework.end(); iter++) {
			if (day < (*iter).second) {
				result += (*iter).first;
				homework.erase(iter);
				break;
			}
		}

		
		
	}
	cout << result;
	return 0;
}