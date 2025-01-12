// If array is almost sorted, Insertion Sort is useful
// But Insertion Sort is often useless best O(N) worst O(N^2)!!!
// pivot 7, next 5 is left to 7 or right to 7?

#include <iostream>

using namespace std;

int n = 10;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--){
            if (target[j] < target[j - 1]) {
                // i = 1, 2, 3, 4
                // j = {1}, {2, 1}, {3, 2, 1}
                swap(target[j], target[j - 1]);
                // if target [3,2,1,0] == 0 < target[2,1,0]
                // 5 7 9 0
                // 5 7 0 9
                // 5 0 7 9
                // 0 5 7 9
            }
            else break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << target[i] << ' ';
    }
    return 0;
}