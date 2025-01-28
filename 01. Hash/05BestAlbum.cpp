#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

/*
다른 풀이
1.
함수생성 pair<int, int> left, right에서 left.first > right.first이면 true,
둘이 같을 때 left.second < right.second이면 true

2.
unordered_map<string, int> summap // 장르 플레이 합
unordered_map<string, vector<pair<int, int>>> genmap; // 장르 내 플레이 높은 순

3.
for (int i = 0; i < genres.size(); i++) {
    summap[genres[i]] += plays[i];
    genmap[genres[i]].push_back(make_pair(plays[i], i));
}

4.
vector<pair<int, string>> fororder;
for (auto x : summap) {
    fororder.push_back(make_pair(x.second, x.first));
}
sort(fororder.begin(), fororder.end());

5.
pair<int, string> temp= fororder.back();
fororder.pop_back();
vector<pair<int, int>> a = genmap[temp.second];
sort(a.begin(), a.end(), compare); // 함수 이름만 넣어도 된다!!!

*/

/*
많이 재생된 장르 > 장르 내 많이 재생된 노래 > 고유번호
장르 play 합 
*/

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genre_plays;
    priority_queue<pair<int, string>> genre_plays_sorted;
    unordered_map<string, priority_queue<pair<int, int>>> pq;
    
    /*
    1. 장르 플레이 높은 순서
    2. 장르 내 플레이 높은 인덱스
    */
    
    
    for(auto i = 0; i < genres.size(); i++){
        genre_plays[genres[i]] += plays[i];
        pq[genres[i]].push({plays[i], -i}); // 1. make_pair(plays[i], i)    2. {plays[i], i}
    }
    
    
    for(auto i : genre_plays){ // auto i == pair<string, int> i
        genre_plays_sorted.push(make_pair(i.second, i.first));
    }
    
    
    while (!genre_plays_sorted.empty()){
        string temp = genre_plays_sorted.top().second;
        genre_plays_sorted.pop();
        
        for (auto j = 0; j < 2; j++){
            if (pq[temp].empty()) break;
            else{
                answer.push_back(-pq[temp].top().second);
                pq[temp].pop();
            }
        }
    }
    
    
    
    
    return answer;
}