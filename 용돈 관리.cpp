#include<iostream>
#include<vector>

using namespace std;

int n, m, k=0;
long long int MAX = 999999999;
int binary(vector<int>&v, int k) {
	long long int start = k;
	long long int end = MAX;

	while (start <= end) {
		long long int mid = (start + end) / 2;
		long long int temp = mid;
		int cnt = 1;

		for (int elem : v) {
			if (temp < elem) {
				temp = mid;
				cnt++;
			}
			temp -= elem;
		}
		if (cnt > m) start = mid + 1;
		else  end = mid - 1;
	}
	return end + 1;
}

int main() {
	cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (k < v[i]) k = v[i];
	}

	cout << binary(v, k);
	return 0;
}