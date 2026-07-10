/*
朴素算法（Dijkstra）

1.特点：
1）非负边权
2）单源最短路径
3）顶点数最好小于1000（ O(n^2) ）
4）适合稠密图

2.伪代码
function Dijkstra(graph, n, s, dist)
    visited[]
    Dijkstra_init(n, s, visited, dist)
    while true
        u = Dijkstra_find_min(n, vistied, dist)
        if u == -1 return
        dijkstra_update(graph, n, u, visited, dist)
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INF INT_MAX

vector<vector<pair<int, int>>> graph = {
    {{1, 4}, {2, 2}},
    {{2, 3}},
    {{3, 4}},
    {}};

int Dijkstra_find_min(vector<bool>& visited, vector<int>& dist) {
    int u = -1;

    for (int i = 0; i < visited.size(); ++i) {
        if (visited[i])
            continue;

        if (u == -1 || dist[i] < dist[u])
            u = i;
    }

    return u;
}

void dijkstra_update(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<int>& dist, int u) {
    visited[u] = 1;

    for (const auto& edge : graph[u]) {
        int vertex = edge.first;
        int weight = edge.second;
        if (visited[vertex])
            continue;

        dist[vertex] = min(dist[vertex], dist[u] + weight);
    }
}

vector<int> Dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    vector<int> dist(graph.size(), INF);

    dist[start] = 0;

    while (true) {
        int u = Dijkstra_find_min(visited, dist);

        if (u == -1 || dist[u] == INF)
            break;

        dijkstra_update(graph, visited, dist, u);
    }

    return dist;
}

int main() {
    vector<int> dist = Dijkstra(graph, 0);

    for (int i = 0; i < dist.size(); ++i) {
        cout << "Distance from vertex 0 to vertex " << i << ": " << dist[i] << endl;
    }

    return 0;
}