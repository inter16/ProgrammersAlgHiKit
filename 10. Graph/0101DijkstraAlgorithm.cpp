// Maybe it is not practical... O(V^2)
// { getSmallestNode = O(V) + j loop = worst O(V) } * O(V) = O(V^2)

#include <vector>
#include <iostream>
#define INF 1e9

using namespace std;

int n, m, start;
// # of node, # of edge, start node #

vector<pair<int, int>> graph[100001];
// graph[x][j] = {y, length} : x to y !!!!

bool visited[100001];
// visited

int d[100001];
// shortest path length

int getSmallestNode() {
    int min_value = INF;
    int index = 0;
    for(int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            // if shortest element is smaller than min, not visited.
            min_value = d[i];
            index = i;
            // save value, index of shortest element
        }
    }
    return index;
    // return index of shortest path ()
}

void dijkstra(int start) {
    d[start] = 0;
    // 1. d[x] = 0;

    visited[start] = true;
    // visited[x] = true; visited right after pushing
    
    for(int j = 0; j < graph[start].size(); j++) { // size of vector
    // # of pair<int, int> which is element of vector<pair<int, int>>, only for x
        
        d[graph[start][j].first] = graph[start][j].second;
        // d[y] = length (adjacent only)
    }
    // initialize d[y]s for x

    for(int i = 0; i < n - 1; i++) {
        int now = getSmallestNode();
        // non-visited i that d[i] is minimum (up to x)
        visited[now] = true;
        // visited i

        for(int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            // cost == d[i] + length of adjacement (for all)
            // x - i - (i adjacement)

            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
                // if d[i] + i-to-y is shorter than current d[y], update
                // cost : start - min d[i] - (i adjacement)
                // d[] : start - (i adjacement)
            }
        }
    }
    // get smallest node n - 1 times, assume that 1 is the shortest
    // assume that graph[1] has {2, 3}, {4, 1} only!!!
    // start - 1 - 2 < start - 2 : update d[2] (start - ? - d[2])
    // start - 1 - 4 < start - 4 : update d[4] (start - ? - d[4])
    // get smallest d[i] (maybe d[4])
    // ...
    // we can find all length of shortest path which is started from start!!!
}

int main(void) {
    cin >> n >> m >> start;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        // initialize graph
    }

    fill_n(d, 100001, INF);
    // (array d, # of elements, value) #include <algorithm>

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if(d[i] == INF) {
            cout << "INFINITY" << '\n';
        }

        else {
            cout << d[i] << '\n';
        }
    }
}