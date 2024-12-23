#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string word) {
    int answer = 0;
    priority_queue<string> pq;
    string s = "AEIOU";
    
    
    string temp = "A";
    
    for (auto i = 1; ; i++){
        if (temp == word){
            answer = i;
            break;
        }
        else if (temp.size() < 5){
            temp.push_back('A');
        }
        else if(temp.back() == 'U'){
            while(temp.back() == 'U'){
                temp.pop_back();
            }
            for (auto j = 0; j < 5; j++){
                if (temp.back() == s[j]){
                    temp.pop_back();
                    temp.push_back(s[j + 1]);
                    break;
                }
            }
            
        }
        
        else{
            for (auto j = 0; j < 5; j++){
                if (temp.back() == s[j]){
                    temp.pop_back();
                    temp.push_back(s[j + 1]);
                    break;
                }
            }
        }
    }
    
    
    
    return answer;
}