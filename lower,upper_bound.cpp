#include<iostream>
#include<vector>
using namespace std;
//이진검색 응용 - lower_bound

//설명 : 배열에서 찾고자하는 값 이상인 최초 지점의 index를 반환

int lower_bound(vector<long long int>& arr, int key, int start, int end) {
	//end에는 배열의 size가 들어와야함.(중요!)

	int mid; 
	while (start < end) { // start와 end가 같은 경우 무한 루프에 빠짐.
		mid = (start + end) / 2;
		if (arr[mid] >= key) end = mid; // <- upper_bound와 다른 유일한 차이점.
		else start = mid + 1;
	}

	return end;
}

//이진검색 응용 - upper_bound

//설명 : 배열에서 찾고자하는 값 보다 큰 최초 지점의 index를 반환

int upper_bound(vector<long long int>& arr , int key, int start, int end) {
	//end에는 배열의 size가 들어와야함.

	int mid;
	while (start < end) { // start와 end가 같은 경우 무한 루프에 빠짐.
		mid = (start + end) / 2;
		if (arr[mid] > key) end = mid; // <- lower_bound와 다른 유일한 차이점.
		else start = mid + 1;
	}
	return end;
}

