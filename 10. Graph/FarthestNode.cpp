#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> d(n + 1);
    fill(d.begin(), d.end(), 1e9);
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    d[1] = 0;
    
    while(!pq.empty()){
        int length = -pq.top().first;
        int index = pq.top().second;
        pq.pop();
        
        if(d[index] < length) continue;
        // why d[index] <= length makes error?
        // d[edge[i][0, 1]] == length + 1 (already updated)
        // At first, length is ALWAYS EQUAL to -pq.top().first
        
        else{
            for(auto i = 0; i < edge.size(); i++){
                if(edge[i][0] == index){
                    if(d[edge[i][1]] > length + 1){
                        d[edge[i][1]] = length + 1;
                        pq.push({-length - 1, edge[i][1]});
                    }
                }
                
                if(edge[i][1] == index){
                    if(d[edge[i][0]] > length + 1){
                        d[edge[i][0]] = length + 1;
                        pq.push({-length - 1, edge[i][0]});
                    }
                }
            }
        }
    }
    
    int maxl = 0;
    
    for(auto i = 1; i <= n; i++){
        if(d[i] == maxl) answer++;
        else{
            if(d[i] != 1e9 && d[i] > maxl){
                maxl = d[i];
                answer = 1;
            }
        }
    }
    
    cout << maxl;
    return answer;
}