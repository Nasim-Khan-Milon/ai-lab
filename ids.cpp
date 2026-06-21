#include <iostream>
#include <vector>

using namespace std;

bool depthLimitedSearch(int node, int target, int limit, const vector<vector<int>>& adj, vector<bool>& inPath) {

    if (node == target)
        return true;

    if (limit == 0)
        return false;

    inPath[node] = true;

    for (int neighbor : adj[node]) {
        if (!inPath[neighbor]) {
            if (depthLimitedSearch(neighbor, target, limit - 1, adj, inPath)) {
                return true;
            }
        }
    }

    inPath[node] = false; 

    return false;
}

bool iterativeDeepeningSearch(int start, int target, int maxDepth, const vector<vector<int>>& adj) {

    for (int limit = 0; limit <= maxDepth; limit++) {
        vector<bool> inPath(adj.size(), false);

        if (depthLimitedSearch(start, target, limit, adj, inPath)) {
            return true;
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
    int maxDepth = 3;

    if (iterativeDeepeningSearch(start, target, maxDepth, adj)) {
        cout << "Target found\n";
    } else {
        cout << "Target not found\n";
    }

    return 0;
}