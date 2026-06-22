#include <bits/stdc++.h>
using namespace std;

void graphColoring(vector<vector<int> >& graph, int V) {

    vector<int> result(V, -1);

    // Assign first color to first vertex
    result[0] = 0;

    // Track unavailable colors
    vector<bool> available(V, true);

    // Assign colors to remaining vertices
    for (int u = 1; u < V; u++) {

        fill(available.begin(), available.end(), true);

        // Mark colors used by adjacent vertices
        for (int i = 0; i < graph[u].size(); i++) {

            int neighbor = graph[u][i];

            if (result[neighbor] != -1)
                available[result[neighbor]] = false;
        }

        // Find first available color
        int color;
        for (color = 0; color < V; color++) {
            if (available[color])
                break;
        }

        result[u] = color;
    }

    // Print result
    cout << "Vertex\tColor\n";

    for (int u = 0; u < V; u++) {
        cout << u << "\t" << result[u] << endl;
    }
}

int main() {

    int V = 5;

    vector<vector<int> > graph(V);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(3);

    graphColoring(graph, V);

    return 0;
}