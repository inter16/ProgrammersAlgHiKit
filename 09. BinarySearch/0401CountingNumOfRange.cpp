#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_by_range(vector<int>& a, int left_value, int right_value){
    int right_index = *upper_bound(a.begin(), a.end(), right_value);
    int left_index = *lower_bound(a.begin(), a.end(), left_value);
    return right_index - left_index;
}

vector<int> a = {1, 2, 3, 3, 3, 3, 4, 4, 8, 9};

int main() {
    cout << count_by_range(a, 4, 4); // the number of 4
    cout << count_by_range(a, -1, 3); // the number of [-1, 3] == [lower_bound, upper_bound]

    return 0;
}