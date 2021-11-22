#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int card[500000];

int lower_bound(int target, int st, int en) {
	int mid=0;
	while (st < en) {
		mid = (st + en) / 2;
		if (card[mid] >= target) en = mid;
		else st = mid + 1;
	}
	return st;
}
int upper_bound(int target, int st, int en) {
	int mid = 0;
	while (st < en) {
		mid = (st + en) / 2;
		if (card[mid] > target) en = mid;
		else st = mid + 1;
	}
	return st;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		cout<< upper_bound(cnt, 0, n)-lower_bound(cnt, 0, n)<<" ";
	}

	

	return 0;
}