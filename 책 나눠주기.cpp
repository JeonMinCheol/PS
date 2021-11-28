#include<iostream>
#include<vector>
#include <cstring>
#include<algorithm>
using namespace std;

int T, N, M, result = 0;
bool book[1000];

void cmp(int big, int small) {
	int temp = N;
	if (temp > big) temp = big;
	if (small > temp) return ;

	for (int i = small-1; i <= temp-1; i++) {
		if (book[i] == false) {
			result++;
			book[i] = true;
			return ;
		}
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;

	vector<pair<int, int>>v;
	while (T--) {
		cin >> N >> M;
		memset(book, false, N);
		v.clear();

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ b,a });
		}
		sort(v.begin(), v.end());

		result = 0;
		for (auto elem : v) {
			cout << elem.first << " " << elem.second << endl;
			cmp(elem.first, elem.second);
		}
		cout << result << endl;
	}
	
	return 0;
}