#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, t;
long long int MAX = 999999999;
long long int search(vector<int>&A, vector<int>&B) {
	long long int result = 0;

	for (int i = 0; i < n; i++) {
		int k = A[i];
		cout<< (static_cast<long long>(lower_bound(B.begin(), B.end(), k) - B.begin()))<<" ";
	}
	return result;
}

int main() {
	cin >> t;

	while (t--) {
		cin>> n >> m;
		vector<int>A(n);
		vector<int>B(m);

		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> B[i];
		}
		sort(B.begin(), B.end());
		cout << search(A, B)<<endl;
	}
	
	

	return 0;
}