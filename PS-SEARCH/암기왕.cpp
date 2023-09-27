#include<iostream>
#include<algorithm>
using namespace std;

int t, n, m;
int note1[1000000];
int lower_bound(int* arr, int key, int start, int end) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= key) end = mid;
		else start = mid + 1;
	}

	return end + 1;
}

int binary(int note2) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (note1[mid] == note2) return 1;
		else if (note1[mid] > note2) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) cin >> note1[j];
		sort(note1, note1 + n);

		cin >> m;
		for (int k = 0; k < m; k++) {
			int note2;
			cin >> note2;
			cout << binary(note2) << "\n";
		}
	}
}