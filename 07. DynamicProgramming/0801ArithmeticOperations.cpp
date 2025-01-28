#include <vector>
#include <string>
using namespace std;
    


int solution(vector<string> arr)
{
    int answer = -1;
    vector<int> n(201);
    vector<int> s(201);
    vector<int> DP(201);
    
    for(auto i = 0; i < arr.size(); i++){
        if(i % 2 == 1){
            n[i] = stoi(arr[i]);
        }
        else{
            /*
            switch(arr[i]) {
                case "+":
                    s[i] = 1;
                    break;
                default:
                    s[i] = 2;
                    break;
            }
            */
        }
    }
    
    if(s[1] == 1) DP[2] = n[0] + n[2];
    else DP[2] = n[0] - n[2];
    
    for(auto i = 3; i <= 100; i++){
        
    }
    
    return answer;
}
// 2 -> 012 3    4-1
// 3 -> 01234 5  6-1
// 4 -> 0123456 7 8-1

// case 0: no bracket after '-'
// case 1: 1 in bracket after '-'
// case n: n in bracket after '-' 
