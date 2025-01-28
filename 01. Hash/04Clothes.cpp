#include <string>
#include <vector>
#include <unordered_map>

/* 
012 01 6 - 1
0123 4 - 1
*/

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for (auto i : clothes){
        um[i[1]] += 1;
    }
    
    for (auto i : um){
        answer *= i.second + 1;
    }
    return answer - 1;
}