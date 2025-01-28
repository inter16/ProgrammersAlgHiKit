#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001];

vector<pair<int, pair<int, int>>> edges;
// {cost, {a, b}}, { , {, }}, ...
int result = 0;

int findParent(int x) {
    if (x == parent[x]) return x;
    // if parent node of x is x, return x
    return parent[x] = findParent(parent[x]);
    // else, find parent of (parent of x)
    // AND ALSO SAVE THE ROOT NODE IN PARENT NODE!!!
    // 4 - 2 - 8, findParent(8) = findParent(2) = findParent(4) = 4
    // parent[8] = 4
    // parent[2] = 4
    // PYRAMID, TRIANGLE FORM
}

void unionParent(int a, int b) {
    a = findParent(a); // a is root node of a
    b = findParent(b); // b is root node of b
    if (a < b) parent[b] = a;
    else parent[a] = b;
    // smaller node is parent of bigger node
}


int main(void) {
    cin >> v >> e;



    for (int i = 1; i <= v; i++) {
        parent[i] = i;
        // root node of i is i itself (disjoint)
        // # of i == # of vertices
    }

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        edges.push_back({cost, {a, b}});
    }

    sort(edges.begin(), edges.end());
    // sort by cost
    // connect minimum cost edges by greedy method!!!

    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (findParent(a) != findParent(b)) {
            // if parent is same, there is already two sides
            unionParent(a, b);
            result += cost;
        }
    }
    cout << result << '\n';
}
