#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int>& dist, vector<bool>& visited, int V) {
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0, 5);
    return 0;
}
