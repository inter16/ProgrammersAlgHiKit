#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(const int& m, const int& n, const vector<vector<int>>& puddles, long long& answer){
    queue<vector<int>> q;
    int length = 0;
    q.push({1, 1, 0});
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int l = q.front()[2];
        vector<int> pud = {0, 0};
        if(length && l > length) return;
        if(x == m && y == n){
            length = l;
            answer++;
        }
        
        for(auto i : puddles){
            if(x + 1 == i[0] && y == i[1]){
                pud[0] = 1;
            }
            if(x == i[0] && y + 1 == i[1]){
                pud[1] = 1;
            }
        }
        
        if(x + 1 <= m && y + 1 <= n){
            if(!pud[0]) q.push({x + 1, y, l + 1});
            if(!pud[1]) q.push({x, y + 1, l + 1});
        }
        
    }
    
}

int solution(int m, int n, vector<vector<int>> puddles) {
    long long answer = 0;
    
    bfs(m, n, puddles, answer);
    return answer;
}