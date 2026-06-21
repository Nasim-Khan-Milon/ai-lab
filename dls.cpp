#include <iostream>
#include <vector>

using namespace std;

bool depthLimitedSearch( int node, int target, int limit, const vector<vector<int>>& adj, vector<bool>& visited ) {
    if (node == target)
        return true;

    if (limit <= 0)
        return false;

    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (depthLimitedSearch( neighbor,  target, limit - 1, adj, visited )) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {3, 4};
    adj[2] = {5};

    int start = 0;
    int target = 5;
    int limit = 2;

    vector<bool> visited(n, false);

    if (depthLimitedSearch(start, target, limit, adj, visited))
        cout << "Target found\n";
    else
        cout << "Target not found within depth limit\n";

    return 0;
}