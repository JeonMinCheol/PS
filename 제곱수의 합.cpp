#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[100001] = {0, 1};
int sum(int x) {
	int& ret = dp[x];
	if (ret != 0) return ret;

	for(int i = 1; i * i <= x; i++) {
		if (i * i == x) {
			return ret = 1;
		}
	}
	
	ret = sum(x - 1) + 1;
	for (int i = 1; i < x; i++) {
		if (i * i < x) ret = min(ret, sum(x - (i * i))+ 1);
		else break;
	}
	return ret;
}
// 18 : 9 , 9 
int main() {
	cin >> n;
	cout << sum(n);

}
