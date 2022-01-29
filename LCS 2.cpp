#include<iostream>
#include<algorithm>
using namespace std;

string s1, s2 , res = "";
int dp[1001][1001] = {};
int main() {
	cin >> s1 >> s2;
	for (int i = 1; i <= s2.size(); i++) {
		char c1 = s2[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) - 1];
		for (int j = 1; j <= s1.size(); j++) {
			char c2 = s1[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(j) - 1];
			if (c1 == c2) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int pv1 = s1.size(), pv2 = s2.size();
	while (pv1 != 0 && pv2 != 0) {
		if (dp[pv2][pv1] == dp[pv2][pv1 - 1]) pv1--;
		else if (dp[pv2][pv1 - 1] == dp[pv2 - 1][pv1]) {
			res += s1[pv1 - 1];
			pv1--;
			pv2--;
		}
		else pv2--;
	}

	for (int i = 0; i <= s2.size(); i++) {
		for (int j = 0; j <= s1.size(); j++) {
			cout << dp[i][j]<<" ";
		}
		cout << endl;
	}
	reverse(res.begin(), res.end());
	cout << dp[s2.size()][s1.size()] <<"\n";
	if (dp[s2.size()][s1.size()] != 0) cout << res;
}