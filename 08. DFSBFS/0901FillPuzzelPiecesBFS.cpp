#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

/*
void dfs(int y, int x, int d, vector<vector<int>>& game_board, vector<vector<int>>& table){
    game_board[y][x] = 1;
    
    for(auto i = 0; i < 4; i++){
        if(0 <= y + dy[i] && y + dy[i] < 6 || 0 <= x + dx[i] < 6){
            if(!game_board[y + dy[i]][x + dx[i]]){
                
                dfs(y + dy[i], x + dx[i]);
            }
        }
    }
}
*/

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    int yn = game_board.size();
    int xn = game_board[0].size();
    
    return answer;
}


/* wrong answer
void bfs1(int y0, int x0, vector<vector<int>>& game_board, vector<vector<int>>& table){
    queue<vector<int>> q;
    q.push(vector<int> {y0, x0, -1});
    game_board[y0][x0] = 1;
    while(!q.empty()){
        int y = q.front()[0];
        int x = q.front()[1];
        int d = q.front()[2];
        q.pop();
        int cnt = 0;
        vector<int> dir(4, 0);
        for(auto i = 0; i < 4; i++){
            if(0 <= y + dy[i] && y + dy[i] < yn && 0 <= x + dx[i] && x + dx[i] < xn){
                if(!game_board[y + dy[i]][x + dx[i]]){
                    q.push(vector<int> {y + dy[i], x + dx[i], i});
                    game_board[y + dy[i]][x + dx[i]];
                    cnt++;
                    dir[i] = 1;
                }
            }
        }
        
        if (cnt == 0) v.push(0);
        else if (cnt == 1){           
            if(d == -1) v.push(0);
            else{
                if(d - 1 == -1 && dir[3] == 1) v.push(2);
                else if(d + 1 == 4 && dir[0] == 1) v.push(3);
                else if(dir[d - 1] == 1) v.push(2);
                else if(dir[d] == 1) v.push(1);
                else if(dir[d + 1]) v.push(3);
                else cout << "error" << " ";
            }
        }
        
        else if (cnt == 2){
            if(d != -1) v.push(4);
            else v.push()
        }
        
        else if (cnt == 3){
            if(d == -1) v.push(4);
            else v.push(5);
        }
        
        else if (cnt == 4 && d == -1) v.push(5);
        
        else cout << "error" << " "; 
    }
}
*/

/*
1: line
2: cw
3: ccw
4: 3
5: 4
*/

