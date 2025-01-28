// Simple Recursion is useless!!!! O(2^n)

#include <iostream>

using namespace std;

int fibo(int x) {
    if (x == 1 || x == 2){
        return 1;
    }
    return fibo(x - 1) + fibo(x - 2);
    // Can use itself in the function
    // f(4) = f(3) + f(2) = f(2) + f(1) + f(2)
}

int main(void) {
    cout << fibo(4) << '\n';
    // fibo ~= DFS!!!!!!
    // if no memoization, process f(3) f(4) (2, 3) each O(2^N)

    // f(6) (f(5) f(4)) (f(4) f(3) f(4)) (f(3) f(2) f(3) f(4))
    // (f(2) f(1) f(2) f(3) f(4)) (1 f(1) f(2) f(3) f(4))
    // (1 1 f(2) f(3) f(4)) (1 1 1 f(3) f(4))
    // useless process : (1 1 1 f(2) f(1) f(4)) (1 1 1 1 f(1) f(4))
    // (1 1 1 1 1 f(4)) (1 1 1 1 1 f(3) f(2))
    // (1 1 1 1 1 f(2) f(1) f(2)) (1 1 1 1 1 1 f(1) f(2)) (1 1 1 1 1 1 1 f(2))
    // (1 1 1 1 1 1 1 1)
    return 0;
}