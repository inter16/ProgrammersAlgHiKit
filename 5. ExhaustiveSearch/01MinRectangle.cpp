#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0;
    int height = 0;
    
    for (auto i = 0; i < sizes.size(); i++){
        width = max(width, max(sizes[i][0], sizes[i][1]));
        height = max(height, min(sizes[i][0], sizes[i][1]));
    }
    
    answer = width * height;
    return answer;
}