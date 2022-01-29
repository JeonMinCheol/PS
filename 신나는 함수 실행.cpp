#include<iostream>
using namespace std;


int a, b, c;
int dp[101][101][101];
int w(int a, int b, int c){
	int& ret = dp[a][b][c];
	if (ret != 0) return ret;

	if (a <= 50 || b <= 50 || c <= 50) ret = 1;
	else if (a > 70 || b > 70 || c > 70) ret = w(70, 70, 70);
	else if (a < b && b < c) ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return ret;
}
int main() {
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) return 0;
		w(a + 50, b + 50, c + 50);
		cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<< dp[a + 50][b + 50][c + 50] << endl;
	}

}