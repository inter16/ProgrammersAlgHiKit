#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

/*
모든 조합을 찾아야 한다
100 010 001 110 101 011 111
2의 7승은 
*/

// set Prime; 선언 후 자동으로 중복을 제거하는 방법이 있다

int solution(string numbers) {
    int answer = 0;
    vector<int> idx;
    int ncount[10];
    map<int, bool> m;
    
    sort(numbers.begin(), numbers.end()); // reverse(numbers.begin(), numbers.end()); 내림차순 가능, alg 헤더
    // sort의 default : return a < b;
    
    for (auto i = 1; i <= numbers.size(); i++){
        do{
            string temps = "";
            for (auto j = 0; j < i; j++){
                temps.push_back(numbers[j]);
            }
            cout << temps << "\n"; // 0 1 1 중복 불가 next_permutation은 중복을 고려하지 않는다
            
            int tempi = stoi(temps);
            bool isPrime = true;
            if (tempi < 2){
                isPrime = false;
                m[tempi] = true;
            }
            for (auto j = 2; j <= sqrt(tempi); j++){
                if (tempi % j == 0){
                    isPrime = false;
                    m[tempi] = true;
                }
            }
            
            if (isPrime && !m[tempi]){
                answer++;
                m[tempi] = true;
            }
                
            
        } while (next_permutation(numbers.begin(), numbers.end()));
        
    }
    
    
    
    
    /*
    오답 : bitmask
    
    for (uint8_t i = 1; i < (1 << (numbers.size())); i++){ // 001 - 111
        int sq = 0;
        for (uint8_t j = 0; j < numbers.size(); j++){ // 0 - 2
            if (i & (1 << j)){
                n_num[i] += (numbers[j] - '0') * pow(10, sq);
                sq++;
            }
        }
        
        cout << n_num[i] << "\n";
        
        bool isPrime = true;
        
        for (auto j = 2; j < sqrt(n_num[i]); j++){
            if (j % i == 0){
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) answer++;
    }
    
    */
    
    
    
    return answer;
}