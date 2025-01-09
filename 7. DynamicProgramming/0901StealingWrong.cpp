#include <string>
#include <vector>

using namespace std;

vector<int> DP(1000000);

int solution(vector<int> money) {
    int answer = 0;
    bool b0 = true;
    bool b2 = true;
    bool bi = true;
    bool bi2 = true;
    
    DP[0] = money[0];
    if(money[1] > DP[0]){
        DP[1] = money[1];
        b0 = false;
        b2 = false;
    }
    else{
        DP[1] = DP[0];
        bi = false;
        bi2 = false;
    }
    
    
    if(DP[1] < money[2]){
        DP[2] = money[2];
        bi = true;
        bi2 = false;
        b0 = false;
        b2 = true;
    }
    else if(money[0] < money[1]){
        DP[2] = DP[1];
        bi = false;
        bi2 = false;
        b0 = false;
        b2 = false;

    }
    else{
        DP[2] = DP[1];
        bi = false;
        bi2 = true;
        b0 = true;
        b2 = false;
    }
    
    if(money[1] + money[3] > money[0] + money[2]){
        DP[3] = money[1] + money[3];
        bi = true;
        bi2 = true;
        b0 = false;
        b2 = false;
    }
    else{
        DP[3] = money[0] + money[2];
        bi = false;
        bi2 = false;
        b0 = true;
        b2 = true;
    }
    
    
    
    for(auto i = 4; i < money.size(); i++){
        if(b0) {
            if(b2) { // 1 3 ... 8
                if(DP[i - 1] - money[0] + money[i] > DP[i - 1]){
                    DP[i] = DP[i - 1] - money[0] + money[i];
                    b0 = false;
                    bi2 = true;
                }
                else{
                    DP[i] = DP[i - 1];
                    bi = false;
                    bi2 = true;
                }
            }
            else{ // 1 4 ... 8
                if(DP[i - 1] - money[0] + money[i] + money[1] > DP[i - 1]){
                    DP[i] = DP[i - 1] - money[0] + money[1] + money[i];
                    bi = true;
                    bi2 = true;
                    b0 = false;
                }
                else{
                    DP[i] = DP[i - 1];
                    bi = false;
                    bi2 = true;
                }
                
            }
        }
        else if(bi){ 
            if(bi2) { // 2 ... 7 9
                if(DP[i - 1] - money[i - 1] + money[i] > DP[i - 1]){
                    DP[i] = DP[i - 1] - money[i - 1] + money[i];
                    bi = true;
                    bi2 = false;
                }
                else{
                    DP[i] = DP[i - 1];
                    bi = false;
                    bi2 = false;
                }
                
            }
            else{ // 2 .. 6 9
                if(DP[i - 1] - money[i - 1] + money[i - 2] + money[i] > DP[i - 1]){
                    DP[i] = DP[i - 1] - money[i - 1] + money[i - 2] + money[i];
                    bi = true;
                    bi2 = true;
                }
                else{
                    DP[i] = DP[i - 1];
                    bi = false;
                    bi2 = false;
                }
            }
            
        }
        else{ // 2 ... 8
            DP[i] = DP[i - 1] + money[i];
            bi = true;
            bi2 = true;
        }
    }
    
    answer = DP[money.size() - 1];
    return answer;
}
    
// 1 3 5 7 < 2 4 6 8 (1 3 6 8)
// 1 3 5 7 < 1 3 5 8 (2 5 8)
// 1 3 5 7 < 1 3 5 8