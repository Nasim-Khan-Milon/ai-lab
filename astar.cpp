#include <bits/stdc++.h>
using namespace std;

int heuristic(int node, int goal) {
    // simple heuristic (you can change it)
    return abs(goal - node);
}

int main() {
    int n = 5;

    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 3});

    int start = 0;
    int goal = 4;

    vector<int> g(n, INT_MAX);
    vector<int> f(n, INT_MAX);

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    g[start] = 0;
    f[start] = heuristic(start, goal);

    pq.push(make_pair(f[start], start));

    while (!pq.empty()) {

        int currentF = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == goal) {
            cout << "Reached goal with cost: " << g[node] << endl;
            return 0;
        }

        for (int i = 0; i < adj[node].size(); i++) {

            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;

            int newG = g[node] + weight;

            if (newG < g[neighbor]) {
                g[neighbor] = newG;

                int h = heuristic(neighbor, goal);
                f[neighbor] = newG + h;

                pq.push(make_pair(f[neighbor], neighbor));
            }
        }
    }

    cout << "Goal not reachable\n";

    return 0;
}