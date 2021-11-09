#include<iostream>
using namespace std;

int container[10] = { 1,2,3,4,7,8,9,10,20,30 };

//반복문을 이용한 이진 탐색
bool binary_search(int* container , int start, int end, int search){
	int mid = (start + end) / 2;
	while (start <= end) {
		if (container[mid] == search) return true;
		else if (container[mid] > search) end = mid - 1;
		else start = mid + 1;
		mid = (start + end) / 2;
	}
	return false;
}

//재귀함수를 이용한 이진 탐색
bool Binary_search(int* container, int start, int end, int search) {
	if (start > end) return false;
	
	int mid = (start + end) / 2;
	
	if (container[mid] == search) return true;
	else if (container[mid] > search) return Binary_search(container, start, mid - 1, search);
	else return Binary_search(container, mid + 1, end , search);
	
	return false;
}
int main() {
	int search;
	cin >> search;

	cout << "result : ";
	if (!binary_search(container, 0, 10, search)) cout << "not ";
	cout << "included.\n";
	
	cout << "result : ";
	if (!Binary_search(container, 0, 10, search)) cout << "not ";
	cout << "included.";


}