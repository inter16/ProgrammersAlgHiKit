// Useful form O(ElogV) -> check it!

// Why O(ElogV)???
// (WHY NOT bigger than O(E)?, WHY NOT O(E^2)?)
// 1. pq push and pop E times, but only V update!!!
// ex) 1-2(1) 1-3(5) 2-4(7) 3-4(6)
// input : {1,0} {1, 2} {5, 3} {8, 4} {11, 4(x)}
// ex) 1-2(1) 1-3(2) 2-4(7) 3-4(3)
// input : {1, 0} {1, 2} {2, 3} {8, 4(x)} {5, 4}

// 2. (while-for) loop TOTAL E TIMES!!!!

// Check All Edges (while-for) (Worst) O(E)
// Push and Sort for All Edges in pq (Worst) = O(logE)

// 3. O(ElogE) = O(Elog(V^2)) = O(2ElogV) = O(ElogV)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, start;

vector<pair<int, int>> graph[100001];

int d[100001];

// visited array is useless!!

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq; // To get smallest node !!!
    pq.push({0, start});
    // {length, index}
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue; // no need to update d[now]

        for (int i = 0; i < graph[now].size(); i++){
            // visit all of now adjacement

            int cost = dist + graph[now][i].second;
            // cost == dist(0 first) + length of adjacement (for all)
            // cost == d[now adj] + length of now adj adj
            
            // start - now - (now adjacement)

            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                // At first, d[now adj] == INF, update to length (now) - (now adj)
                // if start - now adj- now adj adj < start - now adj, push!!!
                pq.push(make_pair(-cost, graph[now][i].first));
                // push {d[now adj], now adj}
                // minimum of d[] will be first!!!
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    for(int i = 1; i <= n; i++){
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }

        else {
            cout << d[i] << '\n';
        }
    }
}