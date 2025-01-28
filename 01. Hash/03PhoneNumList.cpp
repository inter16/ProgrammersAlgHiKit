#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
다른 풀이
1.
for (i : um) um[i] = 1;
2.
for (auto i = 0; i < phone_book.size(); i++){
    string phone_number = "";
    for(int j = 0; j < phone_book[i].size(); j++) {
        phone_number += phone_book[i][j]; // 빈 phone_number에 i번째 원소의 크기만큼 넣어본다
        if(um[phone_number] && phone_number != phone_book[i]) answer = false;
        // 만약 phone_number가 존재하고 그 번호가 선택한 번호와 동일하지 않으면 false 반환.
        // 즉, 모든 번호를 채워넣기전에 앞 일부 번호가 존재하면 false 반환
    }
}    
*/


bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }
    return answer;
}