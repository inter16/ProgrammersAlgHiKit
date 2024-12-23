// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

bool visited[9]; // bool visit
vector<int> graph[9]; // vector<int> linked != python list (cannot insert at once)
// vector<int> linked != python list (cannot insert at once)

void dfs(int x) {
    visited[x] = true; // 1. visited
    cout << x << ' '; // 2. process
    for (int i = 0; i < graph[x].size(); i++){
        // 3. while there exist next visit
        int y = graph[x][i]; // 4. enter x = 1
        // graph = {{}, {2, 3, 8}, {1, 7}}
        // 4. if none condition met, exit and to the previous loop
        if (!visited[y]) dfs(y); // 5. next recursive y = 2, y = 1
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
     // cpp cannot modify arr
     // (arr == pointer, cannot insert at once)

     // index == pointer *(address) == variable 
    dfs(1);
    return 0;
}