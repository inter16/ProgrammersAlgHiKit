#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool dfs(vector<string>& route, vector<vector<string>>& tickets, vector<bool>& used, int depth) {
    if (depth == tickets.size()) {
        answer = route;
        return true; // 경로 완성
        
        // repeat dfs implementation!!!!!
    }

    for (size_t i = 0; i < tickets.size(); ++i) {
        if (!used[i] && tickets[i][0] == route.back()) {
            used[i] = true;
            route.push_back(tickets[i][1]);

            if (dfs(route, tickets, used, depth + 1)) return true;

            route.pop_back();
            used[i] = false;
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 티켓을 사전순으로 정렬
    sort(tickets.begin(), tickets.end()); // can sort vector<vector<string>>!!!!!!!!!!!!

    vector<string> route = {"ICN"};
    vector<bool> used(tickets.size(), false);

    dfs(route, tickets, used, 0);

    return answer;
}


/* wrong answer

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;
vector<vector<string>> answerlist;

void dfs(vector<string>& v, int l, const int& tn, const vector<vector<string>>& tickets, vector<string>& answer){
    um[v.back()] = 1;
    if(l == tn + 1){
        answerlist.push_back(v);
        return;
    }
    
    
        
    for(auto i = 0; i < tn; i++){
        if(tickets[i][0] == v.back() && um[tickets[i][1]] == 0){
            v.push_back(tickets[i][1]);
            dfs(v, l + 1, tn, tickets, answer);
            um[v.back()] = 0;
            v.pop_back();
        }
    }
    
    if(v.size() == 1){
        sort(answerlist.begin(), answerlist.end());
        answer = answerlist[0];
        return;
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    int tn = tickets.size();
    vector<string> v;
    v.push_back("ICN");
    
    dfs(v, 1, tn, tickets, answer);
    
    return answer;
}

*/