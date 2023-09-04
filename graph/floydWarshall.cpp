#include <iostream>
using namespace std;
#define INF 1000000
const int n = 4;
void floyd_Warshall(int graph[][n + 1])
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
void printGraph(int graph[n + 1][n + 1])
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) {
                cout << "INFINITY" << " ";
            }
            else cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
void floyd_Warshal_0index(int graph[][n])
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
void printGraph_0index(int graph[][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n' << '\n';
}
int main()
{
    
    int graph[n + 1][n + 1] = {{0, 0, 0, 0, 0},
                               {0, 0, 3, INF, 7},
                               {0, 8, 0, 2, INF},
                               {0, 5, INF, 0, 1},
                               {0, 2, INF, INF, 0}};

    int second_graph[n][n] = {{0, 3, INF, 7},
                              {8, 0, 2, INF},
                              {5, INF, 0, 1},
                              {2, INF, INF, 0}};

    floyd_Warshall(graph);
    printGraph(graph);
    //floyd_Warshal_0index(second_graph);
    //printGraph_0index(second_graph);
    return 0;
}
