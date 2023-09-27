#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, liquid[100000];
void binary_search(int start, int end) {
	long long int sum = 9999999999;
	int result[2]{};
	while (start < end) {
		if (abs(sum) > abs(static_cast<long long>(liquid[start]) + liquid[end])) {
			sum = static_cast<long long>(liquid[start]) + liquid[end];
			result[0] = liquid[start];
			result[1] = liquid[end];

			
		}
		if (liquid[start] + liquid[end] == 0) {
			cout << result[0] << " " << result[1];
			return;
		}
		else if (liquid[start] + liquid[end] > 0) end--;
		else start++;
	}
	cout << result[0] << " " << result[1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}

	sort(liquid, liquid + n);
	 binary_search(0, n - 1);
		
}