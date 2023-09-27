#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;

int main(void)
{
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());
		vector<int>temp;
		int size = 0;
		for (int i = 0; i < n; i+=2) {
			temp.push_back(v[i]);
		}
		sort(v.begin(), v.end() , greater<>());
		if (n % 2 != 0) {
			for (int i = 1; i < n; i += 2) {
				temp.push_back(v[i]);
			}
		}
		else {
			for (int i = 0; i < n; i += 2) {
				temp.push_back(v[i]);
			}
		}

		int result = abs(temp[n-1] - temp[0]);
		for (int i = 1; i < n; i++) {
			result = max(result, abs(temp[i] - temp[i - 1]));
		}
		
		cout << result<<endl;
	}
	return 0;
}