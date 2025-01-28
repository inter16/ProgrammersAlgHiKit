#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){ // must to memorize the sorting function!!!
    string temp1;
    string temp2;
    
    temp1.append(a); // append() or a + b
    temp1.append(b);
    temp2.append(b);
    temp2.append(a);
    
    return temp1 > temp2;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    bool z = false;
    
    for(auto i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
        if(!z && numbers[i] > 0) z = true;
    }
    
    if (!z) return "0";
    
    sort(v.begin(), v.end(), compare);
    
    for(auto s : v){
        for(auto i = 0; i < s.size(); i++) answer.push_back(s[i]);
    }
    
    return answer;
}