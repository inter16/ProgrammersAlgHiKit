#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    priority_queue<vector<long long>> q;
    sort(times.begin(), times.end());
    for(auto i = 0; i < n; i++){
        int index = lower_bound(times.begin(), times.end(), answer) - times.begin();
        if(i == 0){
            answer = 2 * times[0];
            q.push(vector<long long>{-2 * times[0], times[0], index});
        } else if (index == q.top()[2]){
            answer = -q.top()[0] + q.top()[1];
            q.push(vector<long long>{-q.top()[0] + q.top()[1], q.top()[1], q.top()[2]});
            q.pop();
        }
        else {
            answer = 2 * times[index - 1];
            q.push(vector<long long>{-2 * times[index - 1], times[index - 1], index - 1});
        }
        
    }
    return answer;
}

// 7 14 21 (28) 35 42 49 
// 10 20        30 40 50

// 11 22 33