#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0 ,-1, 0};

vector<vector<int>> graph(102, vector<int> (102, 0));

void bfs(const int& characterY, const int& characterX, const int& itemY, const int& itemX, int& answer){
    queue <vector<int>> q;
    q.push(vector<int> {characterY * 2, characterX * 2, 0});
    graph[characterY * 2][characterX * 2] = 0;
    
    while(!q.empty()){
        int y = q.front()[0];
        int x = q.front()[1];
        int l = q.front()[2];
        cout << q.front()[0];
        cout << q.front()[1];
        cout << q.front()[2] << " ";
        q.pop();
        if(y == itemY * 2 && x == itemX * 2){
            answer = l / 2;
            return;
        }
        
        for(auto i = 0; i < 4; i++){
            if(graph[y + dy[i]][x + dx[i]] == 1){
                q.push(vector<int> {y + dy[i], x + dx[i], l + 1});
                graph[y + dy[i]][x + dx[i]] = 0;
            }
        }
    }

}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 1e9;
    for(auto i = 0; i < rectangle.size(); i++){
        for(auto j = rectangle[i][0] * 2; j <= rectangle[i][2] * 2; j++){
            graph[rectangle[i][1] * 2][j] = 1;
            graph[rectangle[i][3] * 2][j] = 1;
        }
        for(auto j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++){
            graph[j][rectangle[i][0] * 2] = 1;
            graph[j][rectangle[i][2] * 2] = 1;
        }
    }
    
    for (auto i = 0; i < rectangle.size(); i++) {
        int left = rectangle[i][0] * 2;
        int right = rectangle[i][2] * 2;
        int bottom = rectangle[i][1] * 2;
        int top = rectangle[i][3] * 2;
    
        for (int y = bottom + 1; y < top; y++) {
            for (int x = left + 1; x < right; x++) {
                graph[y][x] = 0;
            }
        } // warning!!!! when calculating borderline. Repeat this code
    }
    
    /* wrong part
    for(auto i = 0; i < rectangle.size(); i++){
        for(auto j = 0; j < rectangle.size(); j++){
            if (i == j) continue;
            int ylb = max(rectangle[i][1] * 2, rectangle[j][1] * 2);
            int yrt = min(rectangle[i][3] * 2, rectangle[j][3] * 2);
            int xlb = max(rectangle[i][0] * 2, rectangle[j][0] * 2);
            int xrt = min(rectangle[i][2] * 2, rectangle[j][2] * 2);
            for(auto k = xlb + 2; k < xrt - 1; k++){
                graph[ylb][k] = 0;
                graph[yrt][k] = 0;
            }
            for(auto k = ylb + 2; k < yrt - 1; k++){
                graph[k][xlb] = 0;
                graph[k][xrt] = 0;
            }
        }
    }
    */
    
    bfs(characterY, characterX, itemY, itemX, answer);
    
    return answer;
}

/* wrong answer
#include <string>
#include <vector>
#include <queue>
#include <priority_queue>

using namespace std;



int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<vector<int>> corner;

void bfs(){
    queue<vector<int>> q;
    
    for(auto i = 0; i < corner.size(); i++){
        if(corner[i][0] == characterX){
            if(corner[i][1] == characterY){
                if(corner[i][2] == 1){
                    q.push({characterX, characterY, 0, 0});
                    q.push({characterX, characterY, 3, 0});
                }
                else if(corner[i][2] == 2){
                    q.push({characterX, characterY, 0, 0});
                    q.push({characterX, characterY, 1, 0});
                }
                else if(corner[i][2] == 3){
                    q.push({characterX, characterY, 1, 0});
                    q.push({characterX, characterY, 2, 0});
                }
                else{
                    q.push({characterX, characterY, 2, 0});
                    q.push({characterX, characterY, 3, 0});
                }
            }
            else{
                for(auto j = 0; j < corner.size(); j++){
                    if (j == i) continue;
                    else if(corner[j][0] == characterX){
                        if(corner[i][1] > characterY && characterY > corner[j][1]
                          || corner[i][1] < characterY && characterY < corner[j][1]){
                            q.push({characterX, characterY, 2, 0});
                            q.push({characterX, characterY, 4, 0});
                        } 
                    }
                }
            }
            
        }
        else if(corner[i][1] == characterY){
            for(auto j = 0; j < corner.size(); j++){
                if (j == i) continue;
                else if(corner[j][1] == characterY){
                    if(corner[i][0] > characterX && characterX >= corner[j][0]
                      || corner[i][0] <= characterX && characterX < corner[j][0]){
                        q.push({characterX, characterY, 1, 0});
                        q.push({characterX, characterY, 3, 0});
                    }
                }
            }
        }
    }
    
    
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        int l = q.front()[3];
        q.pop();
        if(x == itemX && y == itemY){
            answer = l;
            return;
        }
        
        for(auto i = 0; i < corner.size(); i++){
            
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 1e9;
    
    for(auto i = 0; i < rectangle.size(); i++){
        corner.push_back({rectangle[i][0], rectangle[i][1], 1});
        corner.push_back({rectangle[i][2], rectangle[i][3], 3});
        corner.push_back({rectangle[i][0], rectangle[i][3], 2});
        corner.push_back({rectangle[i][2], rectangle[i][1], 4});
    }
    
    bfs(); 
    
    return answer;
}
*/