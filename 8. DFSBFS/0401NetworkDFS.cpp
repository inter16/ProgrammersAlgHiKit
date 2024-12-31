#include <string>
#include <vector>
#include <iostream>

using namespace std;

// # define MAX 200

// bool visited[MAX];

int dfs(int idx, vector<int>& visited, int& cnt, int& n, vector<vector<int>>& computers){
    if(visited[idx]) return 0;
    
    visited[idx] = cnt;
    
    cout << idx << " ";
    
    for(auto i = 0; i < n; i++){
        if(!visited[i] && computers[idx][i]){
            dfs(i, visited, cnt, n, computers);
        }
    }
    
    return 1;
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int cnt = 1;
    vector<int> visited(n);
    
    for(auto i = 0; i < n; i++){
        if(dfs(i, visited, cnt, n, computers)) answer++; cnt++; //do not using answer for visited
        // if (visited[i] == 1) continue;
        
        // answer++;
        // visited[i] = 1; // initial setting
        // DFS(i, n, visited, computers)
    }
    
    return answer;
}

/*
A - B - C 같은 네트워크
*/