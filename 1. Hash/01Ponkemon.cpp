#include <vector>
using namespace std; // unordered_map<int, bool> int에서 bool로 매핑

/*
N마리 중에 N/2은
같은 폰켓몬 같은 번호
종류 최댓값
모두 달라야 최댓값
*/

/*
다른 풀이
unordered_map<int, bool> um;
for (auto i : nums) um[i] = true;
return min(um.size(), nums.size() / 2)
*/
int solution(vector<int> nums)
{
    int answer = 0;
    bool poke[200001] = {false}; // 20만개 선언 대신 unordered_map으로 3부터 접근 가늩하게 할 것
    int N = nums.size();
    
    for (auto i : nums){
        if (!poke[i]){
            poke[i] = true;
            answer += 1;
        }
    }
    
    if (answer > N/2) return N/2;
    else return answer;
}