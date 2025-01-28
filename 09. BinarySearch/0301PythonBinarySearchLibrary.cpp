#include <iostream>
#include <vector>
#include <algorithm> // lower_bound, upper_bound, sort

using namespace std;

vector<int> a = {1, 2, 4, 4, 8};
int x = 4;

int main(){
    cout << *lower_bound(a.begin(), a.end(), x) << '\n'; // potential left address of x into a!!!
    cout << *upper_bound(a.begin(), a.end(), x) << '\n'; // potential right address of x into a!!!

    return 0;
}
