#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 0;
    long long end = 1e18;
    
    
    while(start <= end){
        long long temp = (start + end) / 2; 
        long long count = 0;
        for(auto i = 0; i < times.size(); i++){
            count += temp / times[i];
            if(count >= n){
                answer = temp;
                end = answer - 1;
                break;
            }
        }
        if(count < n){
            start = temp + 1;
        }
    }
    return answer;
}

