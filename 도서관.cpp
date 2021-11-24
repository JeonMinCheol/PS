#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n>>m;
	vector<int>left;
	vector<int>right;

	for (int i = 0; i < n; i++) {
		int book;
		cin >> book;
		if (book < 0) left.push_back(-book);
		else right.push_back(book);
	}
	
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int result = 0;
	while (n>0) {
		int locl=999999999, locr = 999999999,  r = 2;
		int lindex, rindex, lsize ,rsize;

		if (left.size() > 0 && left.size() <= m) {
			locl = left[left.size() - 1];
		}
		else if (left.size() > 0) {
			locl = left[m - 1];
			if (left.size() % m != 0) {
				lindex = left.size() % m - 1;
				locl = left[lindex];
			}
		}

		if (right.size() > 0 && right.size() <= m) {
			locr = right[right.size() - 1];
		}
		else if (right.size() > 0) {
			rindex = m - 1;
			locr = right[rindex];
			if (right.size() % m != 0) {
				rindex = right.size() % m - 1;
				locr = right[rindex];
			}
		}
		
		if (locr < locl) {
			int size = m;
			if (right.size() % m != 0) size == (right.size() % m);
			if (right.size() < m) size = right.size();
			
			for (int i = 0; i < size; i++) {
				right.erase(right.begin());
			}
			n -= size;

			if (n == 0) r = 1;
			result += r * locr;
		}
		else {
			int size = m;
			if (left.size() % m != 0) size == (left.size() % m);
			if (left.size() < m) size = left.size();

			for (int i = 0; i < size; i++) {
				left.erase(left.begin());
			}
			n -= size;

			if (n == 0) r = 1;
			result += r * locl;
		}
		cout << result<<"\n";
	}
	cout << result;
	return 0;
}