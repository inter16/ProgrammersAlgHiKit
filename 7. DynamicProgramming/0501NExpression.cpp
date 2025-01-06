// first reach must be simple
// example: 5 (55 25 1 0 10)
// ((555 55*5 55/5 55-5 55+5), ...) 5^5ea

// dp[i] = dp[i - j] (operator) dp[j]


#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> memo(9);

// 0 : plus
// 1 : minus
// 2 : mul
// 3 : div
// 4 : paste

int solution(int N, int number) {
    int answer = -1;
    
    memo[1].insert(N);
    memo[1].insert(-N);
    
    if(N == number) return 1;
    
    int temp = N * 11;
    for(auto i = 2; i < 9; i++){
        memo[i].insert(temp);
        if (temp == number) return i;
        memo[i].insert(-temp);
        temp = temp * 10 + N;
    }
    
    
    for(auto i = 2; i < 9; i++){
        for(auto j = 1; j < i; j++){
            for(auto a : memo[i - j]){
                for(auto b : memo[j]){
                    memo[i].insert(a + b);
                    if(a + b == number) {
                        return i;
                    }
                    memo[i].insert(a - b);
                    if(a - b == number) {
                        return i;
                    }
                    memo[i].insert(a * b);
                    if(a * b == number) {
                        return i;
                    }
                    if (b != 0){
                        memo[i].insert(a / b);
                        if(a / b == number) {
                            return i;
                        }
                    }
                }
            }
        }
    }
    
    
    return answer;
}