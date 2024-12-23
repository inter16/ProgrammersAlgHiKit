#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// v.begin()을 iterator라고 한다.
// & 참조자를 사용할 때 for문에서 iterator + 역참조자 *it 사용하면 속도가 향상된다!!
// find() 함수는 해당 값이 존재하는 iterator를 반환한다. 없으면 v.end() 반환


// 조건식 ? 반환값1 : 반환값2 (심향 연산자 c/c++에만), 조건식이 참이면 반환값1 return, 거짓이면 반환값2 return
// 쉼표 연산자 int a = 2, int b = 3;
// sizeof() : 바이트 수를 반환한다. 변수나 상수를 넣어도 타입의 크기로 변환


int dfs(vector<int> _route, vector<vector<int>>& _dungeons, int _k){
    
    if (_route.size() == _dungeons.size()) return _route.size();
    
    int result = _route.size();
    
    
    for (auto i = 0; i < _dungeons.size(); i++){
        if(find(_route.begin(), _route.end(), i) == _route.end() && _dungeons[i][0] <= _k){
            vector<int> temp = _route;
            temp.push_back(i);
            result = max(result, dfs(temp, _dungeons, _k - _dungeons[i][1]));
        }
    }
    
    /*
    for (auto i = 0; i < _route.size(); i++){
        cout << _route[i];
    }
    */
    
    
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    answer = dfs({}, dungeons, k);
    
    return answer;
}