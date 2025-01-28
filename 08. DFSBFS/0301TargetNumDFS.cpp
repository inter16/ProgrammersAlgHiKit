#include <cmath>
#include <string>
#include <vector>

using namespace std;

/* answer 1

void dfs(int count, int sum, int& length, int& target, int& answer, vector<int>& numbers){
    // Enter parameters after entering the contents of the function
    
    if(count == length){
        if(target == sum){
            answer++;
        }
        return;
    }
    dfs(count + 1, sum + numbers[count], length, target, answer, numbers);
    dfs(count + 1, sum - numbers[count], length, target, answer, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();
    
    dfs(0, 0, length, target, answer, numbers);

    return answer;
}

*/

/* wrong answer

bool visited[64];
vector<int> graph[64];
vector<int> value(64);
int answer = 0;


void dfs(int x, vector<int>& numbers, int& target, int result) {
    visited[x] = true;
    result += value[x];
    for(auto i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y, numbers, target, result);
    }

    if(x >= 32 && target == result) answer++;

    visited[x] = false;
}


int solution(vector<int> numbers, int target) {
    int n = numbers.size();

    for(auto i = 1; i < pow(2, n); i++){
        graph[i] = {i * 2, i * 2 + 1};
    }

    for(auto i = 2; i < pow(2, n + 1); i = i + 2){
        value[i] += numbers[i / 2];
    }

    for(auto i = 3; i < pow(2, n + 1); i = i + 2){
        value[i] -= numbers[i / 2];
    }


    dfs(1, numbers, target, 0);

    return answer;
}

*/

int cnt = 0;

void dfs(vector<int>& numbers, int& target, int idx, int values){
    if(idx == numbers.size() && values == target){
        cnt += 1;
        return;
    }
    
    else if(idx == numbers.size()) return;
    
    dfs(numbers, target, idx + 1, values + numbers[idx]);
    dfs(numbers, target, idx + 1, values - numbers[idx]);
}



int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0);
    answer = cnt;
    return answer;
}

