#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int cache[1001][1001];
int bin(int x, int y) {
	int& ret = cache[x][y];
	if (ret != 0) return ret;
	else if (x == y) {
		ret = 1;
		return 1;
	}
	else if (y == 1) {
		ret = x;
		return x;
	}
	else if (y == 0) {
		ret = 1;
		return 1;
	}
	return ret = (bin(x - 1, y) + bin(x - 1, y - 1)) % 10007;
}
int main() {
	cin >> n >> k;
	fill(&cache[0][0], &cache[0][0] + 1001 * 1001, 0);

	bin(n, k);
	cout << cache[n][k];
}
