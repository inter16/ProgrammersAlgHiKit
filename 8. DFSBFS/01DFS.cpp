// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

bool visited[9]; // 1. bool visit
vector<int> graph[9]; // 2. vector<int> linked == python list

void dfs(int x) {
    visited[x] = true; // visited
    cout << x << ' '; // process
    for (int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i]; // index enter
        if (!visited[y]) dfs(y); // next recursive
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
     // cpp cannot modify arr (arr == pointer)

    dfs(1);
    return 0;
}