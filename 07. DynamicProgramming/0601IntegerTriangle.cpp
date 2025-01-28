#include <string>
#include <vector>

// 9999 * 500 ~= 5*10^6 < 10^9

using namespace std;

vector<vector<int>> DP(500, vector<int> (500));

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int h = triangle.size();
    
    DP[0][0] = triangle[0][0];
    if(h == 1){
        answer = DP[0][0];
        return answer;
    }
    
    for(auto i = 1; i < h; i++){
        DP[i][0] = DP[i - 1][0] + triangle[i][0];
        DP[i][i] = DP[i - 1][i - 1] + triangle[i][i];
        if(i == h - 1){
            answer = max(answer, DP[i][0]);
            answer = max(answer, DP[i][i]);
        }
        for(auto j = 1; j < i; j++){
            DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j]; 
            if(i == h - 1){
                answer = max(answer, DP[i][j]);
            }
        }
    }
    
    
    return answer;
}