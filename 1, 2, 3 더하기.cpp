#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n;
int pl[3] = { 1,2,3 };
int main() {
	cin >> t;
	while (t--) {
		int result = 0;
		cin >> n;
		queue<vector<int>>q;
		vector<int>v(1);
		for (int i = 1; i < 4; i++) {
			v[0] = i;
			q.push(v);
		}

		while (!q.empty()) {
			int x = q.front()[0];
			if (x == n) result++;
			q.pop();

			for (int i = 0; i < 3; i++) {
				v[0] = x + pl[i];
				if (v[0] <= n) q.push(v);
			}
		}
		cout << result<<endl;
	}
	
}