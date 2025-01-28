// FASTEST INTERVAL SUM O(N+M)!!!

#include <iostream>

using namespace std;

int n = 5;
int arr[] = {10, 20, 30, 40, 50};
int prefixSum[6];

int main(){
    int sumValue = 0;

    for (int i = 0; i < n; i++) {
        sumValue += arr[i];
        prefixSum[i + 1] = sumValue;
    }

    int left = 3;
    int right = 4;
    cout << prefixSum[right] - prefixSum[left - 1] << '\n';
    // 10+20+30+40 - 10+20 = 30+40 = P[4] - P[2]
}