// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9]; // bool visit
vector<int> graph[9]; // vector<int> linked

void dfs(int start){
    queue<int> q; // 1. define queue
    q.push(start); // 2. push
    visited[start] = true; // 3. visit
    while(!q.empty()){ // 4. loop while empty
        int x = q.front(); // 5. index front
        q.pop(); // 6. pop
        cout << x <<' '; // 7. process
        for(int i = 0; i < graph[x].size(); i++) {
            // 8. while there exists next visit
            int y = graph[x][i]; // 9. enter x = 1
            // graph = {{}, {2, 3, 8}, {1, 7}}
            if(!visited[y]){ // {2, 3, 8}
                q.push(y); // 9. push all {2, 3, 8}
                visited[y] = true; // 10. visit all
            }
        }
    }
}

int main(void) {
    *graph = {};
    *(graph + 1) = {2, 3, 8}; // *(graph + 1) == graph[1];
    *(graph + 2) = {1, 7};
    *(graph + 3) = {1, 4, 5};
    *(graph + 4) = {3, 5};
    *(graph + 5) = {3, 4};
    *(graph + 6) = {7};
    *(graph + 7) = {2, 6, 8};
    *(graph + 8) = {1, 7};
     // cpp always {}, if int arr[3];
     // cpp cannot modify arr (arr == pointer, cannot insert at once)

    dfs(1);
    return 0;
}