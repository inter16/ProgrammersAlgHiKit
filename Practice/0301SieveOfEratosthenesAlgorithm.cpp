// GOAL : Find all primes smaller than n

#include <iostream>
#include <vector>

using namespace std;

int n = 1000;
vector<int> arr(n + 1, true);

int main() {

    for(int i = 2; i <= (int) sqrt(n); i++) {
        if (arr[i] == true) {
            int j = 2;
            while (i * j <= n) {
                arr[i * j] = false;
                j += 1;
            }
        }
    }


    for (int i = 2; i <= n; i++) {
        if (arr[i]) cout << i << ' ';
    }
}