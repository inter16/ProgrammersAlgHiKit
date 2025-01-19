#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    vector<vector<vector<int>>> DP1(16);
    vector<vector<vector<int>>> DP2(16);
    vector<vector<vector<int>>> DP3(16);
    
    DP1[1] = {{1, 3}}; // 1 to 3
    DP2[1] = {{1, 2}}; // 1 to 2
    DP3[1] = {{2, 3}}; // 2 to 3
    DP1[2] = {{1, 2}, {1, 3}, {2, 3}};
    DP2[2] = {{1, 3}, {1, 2}, {3, 2}};
    DP3[2] = {{2, 1}, {2, 3}, {1, 3}};
    // 13 12 32 DP2[2]/ 13 / 21 23 13 DP3[2]
    
    // 1to2[2] = 1to3[1] + 12 + 3to2[1]
    // 1to2[3] = 1to3[2] + 12 + 3to2[2]
    // 3to2[2] = {3, 1} {3, 2} {1, 2}
    // = rev 2to3[2] = rev {2,1 2,3 1,3} = 1,2 + rev{2,3 1,3} = 1to2[1] + rev{}
    
    for(auto i = 3; i <= 15; i++){
        for(auto& v : DP2[i - 1]){
            DP1[i].push_back(v);
        }
        
        DP1[i].push_back({1, 3});
        
        for(auto& v : DP3[i - 1]){
            DP1[i].push_back(v);
        }
    
    
        
    
        for(auto& v : DP1[i - 1]){
            DP2[i].push_back(v);
        }
        
        DP2[i].push_back({1, 2});
        
        for(int j = DP3[i - 1].size() - 1; j >= 0; j--){
            vector<int> temp = {DP3[i - 1][j][1], DP3[i - 1][j][0]};
            DP2[i].push_back(temp);
        }
    
    
    
        
        for(int j = DP2[i - 1].size() - 1; j >= 0; j--){
            vector<int> temp = {DP2[i - 1][j][1], DP2[i - 1][j][0]};
            DP3[i].push_back(temp);
        }
        
        DP3[i].push_back({2, 3});
        
        for(auto& v : DP1[i - 1]){
            DP3[i].push_back(v);
        }
    }
    
    answer = DP1[n];
    
    return answer;
}

// 1234
// 234 1 0     12
// 34 1 2      13
// 34 0 12     23 (DP1[2])
// 4 3 12      12
// 14 3 2      31
// 14 23 0     32
// 4 123 0     12 (DP2[3])

// 0 123 4     13
// ...