#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto n = 0; n < commands.size(); n++){
        vector<int> vtemp;
        for(auto i = commands[n][0] - 1; i < commands[n][1]; i++){
            vtemp.push_back(array[i]);
        }
        sort(vtemp.begin(), vtemp.end());
        answer.push_back(vtemp[commands[n][2] - 1]);
    }
    
    return answer;
}