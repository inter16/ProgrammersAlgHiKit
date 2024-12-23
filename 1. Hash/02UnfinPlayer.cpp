#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
1명 제외 완주
완주하지 못한 선수 return
*/

string solution(vector<string> participant, vector<string> completion) {  
    int answer = 0;
    
    unordered_map<string, int> um;
    
    
    for(auto i : participant){
        um[i] += 1;
    }
    
    for(auto i : completion){
        um[i] -= 1;
    }
    
    for(auto i : participant){
        if (um[i] > 0) return i; 
    }
}