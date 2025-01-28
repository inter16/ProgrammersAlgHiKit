#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;

int indegree[100001]; // edges into node x

vector<int> graph[100001];

void topologySort() {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(i); // push indegree 0 nodes
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);
        // pop and push indegree 0 nodes into result

        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1;
            // remove edges which is connected with indegree 0 node

            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
                // push indegree 0 nodes after remove edges
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    // 1 -> 4 -> 5
    // 2 -> 3 -> 5
    // q(1, 2)
    // now = 1
    // q(2, 4)
    //
    // result = {1, 2, 4, 3, 5}
}

int main(void) {
    cin >> v >> e;

    for (int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b] += 1;
    }

    topologySort();
}