// GOAL : Determine whether the number is prime or not

#include <iostream>

using namespace std;

bool isPrimeNumber(int x) {
    for (int i = 2; i <= (int) sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
        return true;
    }
}

int main() {
    cout << isPrimeNumber(4) << '\n';
    cout << isPrimeNumber(7) << '\n';
}