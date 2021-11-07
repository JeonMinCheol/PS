#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N, K;
char str[500000];
stack<char>st;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	int index = 0;
	st.push(str[0]);
	index++;

	while (K > 0) {
		if (st.empty()) {
			st.push(str[index]);
			index++;
			continue;
		}

		if (st.top() >= str[index]) {
			st.push(str[index]);
			index++;
		}
		else if (!st.empty()) {
			st.pop();
			K--;
		}
	}

	while (!st.empty()) {
		str[--index] = st.top();
		st.pop();
	}

	for (int i = index; i < N; i++) {
		cout << str[i];
	}
	return 0;
}