#include <iostream>


using namespace std;

long long d[100];

int fibo(int x) {
    cout << 'f(' << x << ')' << ' ';
    
    if (x == 1 || x == 2) {
        return 1;
    }

    if (d[x] != 0) {
        return d[x];
    }

    d[x] = fibo(x - 1) + fibo(x - 2);
    return d[x];
}

int main(void) {
    cout << fibo(6) << '\n';
    // fibo ~= DFS!!!!!!
    // if no memoization, process f(3) f(4) (2, 3) each O(2^N)
    // by memoization, process f(3) f(4) once each O(N)

    // fibo(6) (d[6] = fibo(5) fibo(4)) (d[6] = d[5] fibo(4))
    // (d[6] = fibo(4) fibo(3) fibo(4))
    // (d[6] = d[4] fibo(3) fibo(4))
    // (d[6] = fibo(3) fibo(2) fibo(3) fibo(4))
    // (d[6] = d[3] fibo(2) fibo(3) fibo(4))
    // (d[6] = fibo(2) fibo(1) fibo(2) fibo(3) fibo(4))
    // (d[6] = 1 fibo(1) fibo(2) fibo(3) fibo(4))
    // (d[6] = 1 1 fibo(2) fibo(3) fibo(4))
    // ...
    // queue : f(6) f(5) f(4) f(3) f(2) f(1) f(2) d[3] d[4]
    return 0;
}