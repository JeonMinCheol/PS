#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>&v , int start , int end) {
	if (start >= end) return; // 배열에 원소가 한개일경우 즉 , 정렬이 불가능함. 
	int pivot = start; // pivot값은 정렬의 기준이 되는 값이다.
	int left = pivot + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && v[left] <= v[pivot]) left += 1;
		while (right > start && v[right] >= v[pivot]) right -= 1;
		if (left > right) {
			int a = v[pivot];
			v[pivot] = v[right];
			v[right] = a;
		}
		else {
			int a = v[right];
			v[right] = v[left];
			v[left] = a;
		}
		quicksort(v, start, right - 1);
		quicksort(v, right + 1, end);
	}

}
int main() {
	vector<int>v = { 1,3,5,4,2,6,234,6,2,5,5,3,23,7,43,8457,9,24577,345,1 };
	quicksort(v, 0, v.size() - 1);
	for (auto elem : v) cout << elem << " ";
	return 0;
}