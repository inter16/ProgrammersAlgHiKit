#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<long long>> DP(m + 1, vector<long long>(n + 1, 0));
    
    for(auto v : puddles){
        DP[v[0]][v[1]] = -1;
    }
    
    DP[1][1] = 1;
    
    for(auto i = 1; i <= m; i++){
        for(auto j = 1; j <= n; j++){
            if(i == 1 && j == 1) continue;
            if(DP[i][j] == -1) continue;
            else if(DP[i - 1][j] == -1 && DP[i][j - 1] == -1) DP[i][j] = 0;
            else if(DP[i - 1][j] == -1) DP[i][j] = DP[i][j - 1];
            else if(DP[i][j - 1] == -1) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            
            if(DP[i][j] > 1000000007) DP[i][j] %= 1000000007;
            // long long problem x. it might be problem over 1 billion.
        }
    }
    
    answer = DP[m][n] % 1000000007;
    
    return answer;
}