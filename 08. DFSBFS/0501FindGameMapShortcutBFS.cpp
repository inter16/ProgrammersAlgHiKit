#include <vector>
#include <queue>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


void bfs(vector<vector<int>>& maps, int& answer, const int& n, const int& m){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    maps[0][0] = 0;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int length = q.front().second;
        q.pop();
        if(y == n - 1 && x == m - 1){
            answer = length;
            return;
        }
        for(auto i = 0; i < 4; i++){
            if(0 <= y + dy[i] && y + dy[i] < n && 0 <= x + dx[i] && x + dx[i] < m){
                if(maps[y + dy[i]][x + dx[i]]){
                    q.push({{y + dy[i], x + dx[i]}, length + 1});
                    maps[y + dy[i]][x + dx[i]] = 0;
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 1e9;
    int n = maps.size();
    int m = maps[0].size();
    bfs(maps, answer, n, m);
    if(answer == 1e9) answer = -1;
    return answer;
}