#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    
    for(auto i = 0; i < n; i++){
        if (visited[i]) continue;
        
        q.push({i, 0});
    
        while(!q.empty()){
            int idx = q.front().first;
            int length = q.front().second;
            q.pop();
            // wrong : visited[i] = true; -> i in queue might be false
            // always visited[i] = true; right after pusing into queue (i in queue might be false)
            for(auto j = 0; j < n; j++){
                if(!visited[j] && computers[idx][j]){
                    q.push({j, length + 1});
                    visited[j] = true;
                }
            }
        }
        
        answer++;
    }

    
        
    return answer;
}