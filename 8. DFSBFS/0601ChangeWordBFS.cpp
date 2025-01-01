#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> visited(50, 0);

void bfs(string& begin, string& target, int& answer, vector<string>& words){
    queue<pair<int, string>> q;
    q.push({0, begin});
    while(!q.empty()){
        int length = q.front().first;
        string current = q.front().second;
        q.pop();
        if (current == target){
            answer = length;
            return;
        }
        for(auto i = 0; i < words.size(); i++){
            int cnt = 0;
            for(auto j = 0; j < words[0].size(); j++){
                if(words[i][j] == current[j]) cnt++;
            }
            if(!visited[i] && cnt == current.size() - 1){
                q.push({length + 1, words[i]});
                visited[i] = 1;
            }
        }
         
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 1e9;
    
    bfs(begin, target, answer, words);
    
    if(answer == 1e9) answer = 0;
    return answer;
}