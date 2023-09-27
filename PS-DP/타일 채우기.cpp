#include<iostream>
#include<algorithm>
using namespace std;

int n;
int cache[31] = {1};
int dp[31] = {1};
int tile(int x) {
	if (x % 2 != 0) return 0;
	else {
		int& ret = cache[x];
		if (ret != 0) return ret;
		ret += 3 * tile(x - 2);
		for (int i = x - 4; i >= 0; i--) {
			ret += 2 * tile(i);
		}
		return ret;
	}
}

int main() {
	cin >> n;
	cout << tile(n);
}
