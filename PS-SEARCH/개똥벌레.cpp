#include<iostream>
#include<algorithm>
using namespace std;

int n, h;
int low[100000], high[100000];

int lower_bound(int* arr, int key, int start, int end) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= key) end = mid;
		else start = mid + 1;
	}

	return end + 1;
}

int main() {
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		cin >> low[i] >> high[i];
	}

	sort(low, low + n / 2);
	sort(high, high + n / 2);

	int MIN = 999999999;
	int cnt = 1;
	for (int i = 1; i <= h; i++) {
		int lo = n/2 - lower_bound(low, i, 0, n / 2) + 1;
		int hi = n/2 - lower_bound(high, h - i + 1, 0, n / 2) + 1;

		if (MIN > lo + hi) {
			MIN = lo + hi;
			cnt = 1;
		}
		else if (MIN == lo + hi) {
			cnt++;
		}
	}
	cout << MIN << " " << cnt;
}