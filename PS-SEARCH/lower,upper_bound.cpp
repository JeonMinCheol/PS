#include<iostream>
#include<vector>
using namespace std;
//�����˻� ���� - lower_bound

//���� : �迭���� ã�����ϴ� �� �̻��� ���� ������ index�� ��ȯ

int lower_bound(vector<long long int>& arr, int key, int start, int end) {
	//end���� �迭�� size�� ���;���.(�߿�!)

	int mid; 
	while (start < end) { // start�� end�� ���� ��� ���� ������ ����.
		mid = (start + end) / 2;
		if (arr[mid] >= key) end = mid; // <- upper_bound�� �ٸ� ������ ������.
		else start = mid + 1;
	}

	return end;
}

//�����˻� ���� - upper_bound

//���� : �迭���� ã�����ϴ� �� ���� ū ���� ������ index�� ��ȯ

int upper_bound(vector<long long int>& arr , int key, int start, int end) {
	//end���� �迭�� size�� ���;���.

	int mid;
	while (start < end) { // start�� end�� ���� ��� ���� ������ ����.
		mid = (start + end) / 2;
		if (arr[mid] > key) end = mid; // <- lower_bound�� �ٸ� ������ ������.
		else start = mid + 1;
	}
	return end;
}

