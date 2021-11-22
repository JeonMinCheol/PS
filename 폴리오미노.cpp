#include<iostream>
#include<algorithm>
using namespace std;

string st, res="";
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> st;
	int size = st.size(), cnt = 0;
	for (int i = 0; i < size; i++) {
		if (st[i] != '.') {
			cnt++;
			if(i != size-1) continue;
		}
		
		if (cnt % 2 != 0) {
			cout << -1;
			return 0;
		}

		for (int j = 0; j < cnt / 4; j++) {
			res += "AAAA";
		}
		cnt %= 4;
		for (int j = 0; j < cnt; j++) {
			res += "B";
		}
		if (st[i] == '.') {
			res += '.';
			cnt = 0;
		}
	}
	cout << res;
	
	return 0;
}