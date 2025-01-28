#include <iostream>

// save bottom result, no repeat at bottom index
// memoization(Caching) vs bottomup
// memory vs DP table

// memoization means temporary save in the past only!!!!

using namespace std;

long long d[100];

int fibo(int x){
    if (x == 1 || x == 2) {
        return 1;
    }
    if (d[x] != 0) {
        return d[x];
    }

    d[x] = fibo(x - 1) + fibo(x - 2);
    return d[x];
}

int main(void){
    cout << fibo(99) << '\n';
    return 0;
}