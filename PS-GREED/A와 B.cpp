#include<iostream>
#include<algorithm>
using namespace std;

string st, re;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> st >> re;

	int size = re.size(), ssize = st.size();
	for (int i = size - 1; i > 0; i--) {
		if (re[i] == 'A') re = re.substr(0, size - 1);
		else {
			re = re.substr(0, size - 1);
			reverse(re.begin(), re.end());
		}
		size -= 1;
		if (ssize == size) {
			if (re == st) cout << 1;
			else cout << 0;
			return 0;
		}
	}
	return 0;
}