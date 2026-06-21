#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; // number of nodes

    vector<vector<pair<int,int>>> adj(n);

    // edges: {node, weight}
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});

    adj[1].push_back({3, 2});

    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});

    adj[4].push_back({3, 9});

    int source = 0;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push(make_pair(0, source));

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currentDist > dist[node])
            continue;

        for (int i = 0; i < adj[node].size(); i++) {

            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}