#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/* 다른 풀이
vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end()); // *max_element에 대해 공부할 것
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;

*/

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> supo1 = {1, 2, 3, 4, 5};
    vector<int> supo2 = {1, 3, 4, 5};
    vector<int> supo3 = {3, 1, 2, 4, 5};
    vector<int> score(4);
    priority_queue<pair<int, int>> pq;
    
    for (auto i = 0; i < answers.size(); i++){
        if(supo1[i%5] == answers[i]) score[1] += 1;
        if(i % 2 == 0 && answers[i] == 2) score[2] += 1;
        if(i % 2 == 1 && supo2[((i - 1)/2) % 4] == answers[i]) score[2] += 1;
        if(supo3[(i / 2) % 5] == answers[i]) score[3] += 1;
    }
    
    for (auto i = 0; i < 3; i++){
        pq.push({score[i + 1], - (i+1)});
    }
    
    while(!pq.empty()){
        int temp = pq.top().first;
        answer.push_back(- pq.top().second);
        pq.pop();
        if (pq.top().first != temp) break;
    }
    
    
    return answer;
}