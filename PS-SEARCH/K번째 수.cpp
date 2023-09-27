#include<iostream>
#include<cmath>
using namespace std;

long long int n, k;
long long int binary_search(long long int start, long long int end) {
	long long int mid , result;
	while (start <= end) {
		long long int cnt = 0;
		mid = (start + end) / 2;

		for (long long int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}
		if (cnt > k) end = mid - 1;
		else {
			start = mid + 1;
			result = start;
		}
	}
	return result;
}

int main() {
	cin >> n>>k;
	cout << binary_search(1, k);
}