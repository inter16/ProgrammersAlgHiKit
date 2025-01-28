


/* wrong answer DFS

#include<vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1 ,0};

int lMin = 100;

vector<vector<int>> visited(5, vector<int> (5, 0));

void dfs(int y, int x, int& n, int& m, vector<vector<int>>& maps, int length){
    if(y == n - 1 && x == m - 1){
        lMin = min(lMin, length);
        return;
    }
    
    visited[y][x] = 1;
    
    
    for(auto j = 0; j < 4; j++){
        if(0 <= y + dy[j] && y + dy[j] < n && 0 <= x + dx[j] && x + dx[j] < m){
            if(maps[y + dy[j]][x + dx[j]] && !visited[y + dy[j]][x + dx[j]]){
                dfs(y + dy[j], x + dx[j], n, m, maps, length + 1);
                visited[y + dy[j]][x + dx[j]] = 0;
            }
        }
    }
    return;
}



int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    dfs(0, 0, n, m, maps, 1);
    
    
    if(lMin == 100) answer = -1;
    else answer = lMin;
    
    return answer;
}

*/