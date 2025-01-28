#include <iostream>

using namespace std;

int v, e;
int parent[100001];

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
        int a, b;
        cin >> a >> b;
        unionParent(a, b); // merge, acquisition
        // # of acquisition == # of edges
    }

    cout << "각 원소가 속한 집합: ";
    for (int i = 1; i <= v; i++) {
        cout << findParent(i) << ' ';
        // classify sets by root nodes
    }
    cout << '\n';

    cout << "부모 테이블: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
        // classify sets by root nodes
    }
    cout << '\n';

}