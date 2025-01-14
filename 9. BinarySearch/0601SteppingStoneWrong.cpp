#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 1e9;
    vector<int> d1;
    vector<int> d2;
    priority_queue<pair<int, int>> tempd1;
    
    
    rocks.push_back(0);
    rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    
    for(auto i = 1; i < rocks.size(); i++){
        tempd1.push({-(rocks[i] - rocks[i - 1]), i});
    }
    
    for(auto i = 1; i < rocks.size() - 1; i++){
        d2.push_back(rocks[i + 1] - rocks[i - 1]);
    }
    
    for(auto i = 0; i < n; i++){
        int value = tempd1.top().first;
        while(value == tempd1.top().first){
            int index = tempd1.top().second;
            tempd1.pop();
            if(index == rocks.size() - 1) tempd1.push({-(rocks[index] - rocks[index - 2]), index});
            else if(index == 1) tempd1.push({-(rocks[index + 1] - rocks[index - 1]), index + 1});
            else if(d2[index] <= d2[index - 1]) tempd1.push({-(rocks[index + 1] - rocks[index - 1]), index + 1});
            else tempd1.push({-(rocks[index] - rocks[index - 2]), index});
        }
    }
            
    
    
    answer = -tempd1.top().first;
    
    return answer;
}