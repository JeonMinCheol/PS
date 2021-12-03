#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


int n, m, result;
bool check[100000];

int binary(vector<vector<pair<int, int>>>&v, int a, int b) {
	int left = 1, right = 1000000000, mid;
	
	while (left <= right) {
		queue<pair<int, int>>q;
		memset(&check[0], false, 100000);
		mid = (left + right) / 2;
		check[a] = true;
		q.push({ a, 1000000001 });
		
		while (!q.empty()) {
			int index = q.front().first;
			int weight = q.front().second;
			q.pop();

			if (index == b) {
				left = mid + 1;
				result = mid;
				break;
			}

			for (int i = 0; i < v[index].size(); i++) {
				int size = v[index][i].second;
				if (size >= mid) {
					int iindex = v[index][i].first;
					if (check[iindex]) continue;
					q.push({ iindex , min(weight , size) });
					check[iindex] = true;
				}
			}

		}
		if (!check[b]) {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	vector<vector<pair<int,int>>>v(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a-1].push_back({ b-1,c });
		v[b-1].push_back({ a-1,c });
	}

	int a, b;
	cin >> a >> b;
	cout<<binary(v, a-1, b-1);


}