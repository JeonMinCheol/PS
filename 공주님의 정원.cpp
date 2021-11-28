#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
bool cmp(vector<int>a, vector<int>b) {
	if (a[0] > b[0]) return true;
	if (a[0] == b[0]) {
		if (a[1] > b[1]) return true;
		else if (a[1] == b[1]) {
			if (a[2] > b[2]) return true;
			else if (a[2] == b[2]) {
				if (a[3] > b[3]) return true;
			}
		}
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	vector<vector<int>>flower;
	for (int i = 0; i < n; i++){
		vector<int>temp(4);
		cin >> temp[2] >> temp[3] >> temp[0] >> temp[1]; // 끝나는 크기 순서대로 정렬.
		flower.push_back(temp);
	}
	sort(flower.begin(), flower.end(), cmp);
	

	int cnt = 0;
	vector<int>point;
	for (int i = 0; i < n; i++) {
		if (flower[i][2] < 3 || (flower[i][2] == 3 && flower[i][3] == 1)) {
			point = flower[i];
			cnt++;
			break;
		}
	}

	
	while (point[0] <= 11) {
		vector<int>temp = point;

		for (int i = 0; i < n; i++) {
			if (flower[i][2] < point[0] || (flower[i][2] == point[0] && flower[i][3] <= point[1])) {
				point = flower[i];
				cnt++;
				break;
			}
		}

		if (point == temp) {
			cout << 0;
			return 0;
		}
	}
	
	cout << cnt;
	return 0;
}