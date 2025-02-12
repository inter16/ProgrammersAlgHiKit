#include <iostream>

#define INF 1e9

using namespace std;

int n, m;
// # of nodes, # of edges

int graph[501][501];
// graph with direction (Arrow)

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < 501; i++) {
        fill(graph[i], graph[i] + 501, INF);
        // fill(array begin, array end, value);
        // fill_n(array begin, # of variables, value);
    }

    for(int a = 1; a <= n; a++) {
        for(int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
            // diagonal = 0
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for(int k = 1; k <= n; k++) {
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            // for all k, graph[a][b] = min(a-b, a-k-b)
            // if already updated, graph[a][b] = min(a-?-b, a-?-k-?-b);
            }
        }
    }

    for (int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            if (graph[a][b] == INF){
                cout << "INFINITY" << ' ';
            }

            else {
                cout << graph[a][b] << ' ';
            }
        }
        cout << '\n';
    }
}