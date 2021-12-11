#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n, s;
	
int main() {
	cin >> n >> s;
	vector<int>v(n), first(pow(2, n / 2)), second(pow(2, n / 2));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < pow(2, n / 2); i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i & (1 << j)) first[i] += v[j];
		}
	}

	for (int i = 0; i < pow(2, n / 2); i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i & (1 << j)) second[i] += v[j + n / 2];
		}
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<>());

	long long int idx1 = 0, idx2 = 0;
	long long int result = 0;
	while (idx1 < pow(2, n / 2)&& idx2 < pow(2, n / 2)) {
		if (first[idx1] + second[idx2] < s) idx1++;
		else if (first[idx1] + second[idx2] > s) idx2++;
		else {
			long long int cnt = 1 , cnt2 = 1;
			idx1++, idx2++;

			while (idx1 <pow(2, n / 2) && first[idx1] == first[idx1-1]) {
				idx1++;;
				cnt++;
			}

			while (idx2 < pow(2, n / 2) && second[idx2] == second[idx2 - 1]) {
				idx2++;;
				cnt2++;
			}
			result += cnt * cnt2;
		}
	}
	cout << result;
}