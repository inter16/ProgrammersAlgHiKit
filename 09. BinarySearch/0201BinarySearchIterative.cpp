/// Binary Search : to find specific data O(log_(2)N)
// ASSUME ARRAY IS ALREADY SORTED!!!!!!

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>&arr, int target, int start, int end) {
    // I WANT TO FIND THE TARGET
    while (start <= end){ // When start is bigger than end, finish
        int mid = (start + end) / 2;

        if(arr[mid] == target) return mid; // RETURN TARGET INDEX

        // if target != arr[4], answer is not 4.
        else if (arr[mid] > target) end = mid - 1;
        // target is too small, 0 ~ 9 -> 0 ~ 3

        else start = mid + 1;
        // target is too big, 0 ~ 9 -> 5 ~ 9
    }
    return -1;
}

int n, target;
vector<int> arr;

int main(void) {
    cin >> n >> target;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n'; // (INDEX + 1)th number
    }
    return 0;
}