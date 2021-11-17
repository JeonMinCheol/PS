#include <iostream>
#include <string>

using namespace std;
string t;
bool U, C, P, CC;
int main(void)
{
	getline(cin,t);
	U = false;
	C = false;
	P = false;
	CC = false;

	int size = t.size();
	for (int i = 0; i < size; i++) {
		if (t[i] == 'U') U = true;
		if (U && t[i] == 'C') C = true;
		if (C && t[i] == 'P') P = true;
		if (P && t[i] == 'C') CC = true;

	}

	if (U && C && P && CC) cout << "I love UCPC" << endl;
	else cout << "I hate UCPC" << endl;
	return 0;
}