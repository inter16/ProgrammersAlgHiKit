#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();
    
    queue<pair<int, int>> q;
    // if dfs function has 2 variables, queue will also have 2.
    q.push({0, 0}); // changeable numbers!!! count = 0, sum = 0
    while(!q.empty()){
        int count = q.front().first;
        int sum = q.front().second;
        q.pop();
        if(count == length){
            if(sum == target){
                answer++;
            }
            continue;
        }
        q.push({count + 1, sum + numbers[count]});
        q.push({count + 1, sum - numbers[count]});
    }
    
    return answer;
}