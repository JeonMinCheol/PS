#include<iostream>
using namespace std;

int k, n;
long long int length, result;
long long int lan[10000];

void binary_search(long long int start, long long int end) {
	while (start <= end) {
		result = 0;
		long long int mid = (static_cast<long long>(start) + end) / 2;
		for (int i = 0; i < k; i++) result += lan[i] / mid;

		if (result >= n) {
			length = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
}
int main() {
	long long int big = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		if (lan[i] > big) big = lan[i];
	}
	if (n == 1) {
		cout << big;
		return 0;
	}
	binary_search(1, 2147483647);
	cout << length;
	return 0;
}