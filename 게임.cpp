#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long int x,y;
long double z;

long long int binary() {
	long long int integer = static_cast<long long int>(z);
	long long int start = 1, end = 5000000000, mid = (start + end) / 2, result = -1;
	long double per;

	while (start <= end) {
		mid = (start + end) / 2;
		per = 100 * (static_cast<long double>(mid + y) / (mid + x));
		if (static_cast<long long int>(per) - integer > 0) {
			result = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return result;
}

int main() {
	cin >> x >> y;
	z = 100 * (static_cast<long double>(y) / x);
	cout << binary();
}