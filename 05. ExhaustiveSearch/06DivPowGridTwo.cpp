#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;


int solution(int n, vector<vector<int>> wires) {    
    
    int answer = n;
    
    for(auto i = 0; i < n - 1; i++){
        vector<int> visited_n(n + 1, 0); // visited_n이 자연수 체크임을 확인!!! -> 일부만 틀리면 범위를 생각하라
        vector<int> visited_w(n - 1, 0);
        
        visited_w[i] = 1;
        int cnt = 0;
        
        queue<int> q;
        
        if(!visited_w[0]){ // !visited 이용할 때 0인지 1인지 잘 판단해라!!!!
            q.push(wires[0][0]);
        }
        else{
            q.push(wires[1][0]);
        }
    
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cnt++;
            visited_n[temp] = 1;
            
            for(auto j = 0; j < n - 1; j++){
                if(!visited_w[j]){
                    if(wires[j][0] == temp && !visited_n[wires[j][1]]){
                        q.push(wires[j][1]);
                        visited_w[j] = 1;
                    }
                    else if(wires[j][1] == temp && !visited_n[wires[j][0]]){
                        q.push(wires[j][0]);
                        visited_w[j] = 1;
                    }
                }
            }
        }
        
        answer = min(answer, abs(n - cnt * 2));

//         for(auto a : visited_n){ 
//             a = false;
//         }
        
//         for(auto b : visited_w){
//             b = false;
//         }
//  for(auto& i : v) 반복문을 사용할 것!!! 여기서 a는 call by value에 의한 복사본이다!!
    }
    
    return answer;
}