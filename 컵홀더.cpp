#include<iostream> 
#include<string> 
#include<algorithm> 
using namespace std;
string x;
int result = 1 , Size;
void cnt(string x) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '*') result++;
	}
}
int main() {
	cin >> Size >> x;
	for (int i = 1; i < Size; i++) {
		if (x[i] == 'L') {
			if (x[i - 1] == 'L') {
				x.insert(i + 1, "*");
				Size++;
				i++;
			}
			else if (x[i - 1] != '*') {
				x.insert(i, "*");
				Size++;
				i++;
				continue;
			}
		}
		if (x[i] == 'S') {
			if (x[i - 1] != '*') {
				x.insert(i, "*");
				Size++;
				i++;
			}
			else {
				x.insert(i + 1, "*");
				Size++;
				i++;
			}
			
		}
	}
	cnt(x);
	cout << result;
}
