#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for(auto i = 0; i < n; i++){
        if(n - i <= citations[i]) return n - i;
    }
}