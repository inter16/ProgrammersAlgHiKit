// Quick Sort is usually useful best O(N) ~ O(NlogN) (v.sort())
// But Insertion Sort sometimes useless iff array is almost sorted worst O(N^2) (But v.sort() : O(NlogN))

#include <iostream>
#include <algorithm>

using namespace std;

int n = 10;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void quickSort(int* target, int start, int end) {
    if (start >= end) return;
    int pivot = start; // pivot == 0;
    int left = start + 1; // left == 1;
    int right = end; // right == 9;
    while (left <= right) { // until left is bigger than right
        while(left <= end && target[left] <= target[pivot]) left++;
        // if target[left] is bigger than target[0] or left == 10, finish
        // target[left] == 9, left == 2
        while(right > start && target[right] >= target[pivot]) right--;
        // if target[right] is equal or smaller than target[0] or right == 0, finish
        // target[right] == 4, right == 8
        if (left > right) swap(target[pivot], target[right]);
        // swap() (algorithm) : swap var1, var2 (if left is right to right, swap target[0], target[right])
        else swap(target[left], target[right]); // else, swap target[left], target[right]

        // [7] 5 <9) 03162 (4> 8
        // [7] 5 <4) 03162 (9> 8
        // [7] 540316 (2> <9) 8
        // [2] 540316 (7> <9) 8
    }
    quickSort(target, start, right - 1);
        // [2] <5) 403 (1> 6798
        // [2] <1) 403 (5> 6798
        // [2] 1 <4) (0> 356798
        // [2] 1 <0) (4> 356798
        // [2] 1 (0> <4) 356798
        // [0] 1 (2> <4) 356798

        // [0] <1> 24356798
        // ([0]> <1) 24356798
        // ([0]> <1) 24356798 return;
        
        // 012 [4] (3> <5) 6798
        // 012 [3] (4> <5) 6798

        // 012 ([3]> 456798 return;

        // 01234 ([5]> <6)798 return;

        // 0123 (4> [5] 6798 return;

        // ...

    quickSort(target, right + 1, end); // WARNING!!! RECURSIVE!!!
        // xxxxxxxx [9] <8>
        // xxxxxxxx [9] (8> <)
        // xxxxxxxx [8] (9> <)
        

}

int main(void) {
    quickSort(target, 0, n - 1); // start == 0, end == 9
    for (int i = 0; i < n; i++) cout << target[i] << ' ';
    return 0;
}