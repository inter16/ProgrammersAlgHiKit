#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// yellow 6*4 brown 8+8+4+4

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    set<pair<int, int>> yellow_d;
    
    
    yellow_d.insert({1, yellow});
    
    for (auto i = 2; i <= sqrt(yellow); i++){
        if (yellow % i == 0){
            yellow_d.insert({i, yellow/i});
        }
    }
    
    for (auto i = yellow_d.begin(); i != yellow_d.end(); i++){
        if((*i).first * 2 + (*i).second * 2 + 4 == brown){
            answer.push_back((*i).second + 2);
            answer.push_back((*i).first + 2);
            break;
            // answer = {(*i).second + 2, (*i).first + 2}; 사용해도 무방
        }
    }
    
    
    
    return answer;
}