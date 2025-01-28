// GOAL : Find # of subarray which is equal to m

#include <iostream>

using namespace std;

int n = 5; // # of data
int m = 5; // partial sum
int arr[] = {1, 2, 3, 2, 5};

int main() {
    int cnt = 0, intervalSum = 0, end = 0;
    for (int start = 0; start < n; start++) {
        // if one loop is ended, start++
        while (intervalSum < m && end < n) {
            intervalSum += arr[end];
            // intervalSum is always smaller than m
            // first, intervalSum == 0
            // intervalSum += arr[0]
            // intervalSum == 1
            end += 1;
            // end == 1
        }
        if (intervalSum == m) {
            cnt += 1;
        }
        intervalSum -= arr[start];
        // if intervalSum >= m
        // subtract arr[start] from the intervalSum
    }
    cout << cnt << '\n';
}