#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
long long int binary_search(vector<int>& v) {
    long long int result = 0;
    long long int start = 0, end = 1000000000000000000;

    while (start <= end) {
        long long int mid = (start + end) / 2;
        long long int cnt = 0;

        for (int elem : v) {
            cnt += mid / elem;
            if (cnt >= m) {
                result = mid;
                end = mid - 1;
                break;
            }
        }
        if (end != mid - 1) start = mid + 1;
    }
    return result;
}

int main() {
    cin >> n >> m;
    vector<int>time(n);
    
    for (int i = 0; i < n; i++) 
        cin >> time[i];
    
    sort(time.begin(), time.end());
    cout<<binary_search(time);
}
