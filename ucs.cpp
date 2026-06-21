// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     map<string, vector<pair<string,int>>> graph;

//     graph["Main Gate"].push_back({"Library",4});
//     graph["Library"].push_back({"Main Gate",4});

//     graph["Main Gate"].push_back({"Cafeteria",2});
//     graph["Cafeteria"].push_back({"Main Gate",2});

//     graph["Library"].push_back({"Academic Building A",5});
//     graph["Academic Building A"].push_back({"Library",5});

//     graph["Cafeteria"].push_back({"Academic Building A",8});
//     graph["Academic Building A"].push_back({"Cafeteria",8});

//     graph["Cafeteria"].push_back({"Central Field",10});
//     graph["Central Field"].push_back({"Cafeteria",10});

//     graph["Academic Building A"].push_back({"IICT",6});
//     graph["IICT"].push_back({"Academic Building A",6});

//     graph["Central Field"].push_back({"IICT",3});
//     graph["IICT"].push_back({"Central Field",3});

//     graph["Library"].push_back({"Central Field",7});
//     graph["Central Field"].push_back({"Library",7});

//     string start = "Main Gate";
//     string goal = "IICT";

//     priority_queue<
//         pair<int,string>,
//         vector<pair<int,string>>,
//         greater<pair<int,string>>
//     > pq;

//     map<string,int> dist;
//     map<string,string> parent;
//     set<string> visited;

//     pq.push({0,start});
//     dist[start] = 0;

//     int expanded = 0;

//     while(!pq.empty()) {
//         auto top = pq.top();
//         pq.pop();

//         int currentCost = top.first;
//         string currentNode = top.second;

//         if(visited.count(currentNode)) continue;

//         visited.insert(currentNode);
//         expanded++;

//         if(currentNode == goal) break;

//         for(auto &edge : graph[currentNode]) {
//             string nextNode = edge.first;
//             int newCost = currentCost + edge.second;

//             if(!dist.count(nextNode) || newCost < dist[nextNode]) {
//                 dist[nextNode] = newCost;
//                 parent[nextNode] = currentNode;
//                 pq.push({newCost,nextNode});
//             }
//         }
//     }

//     vector<string> path;
//     string node = goal;

//     while(node != "") {
//         path.push_back(node);
//         node = parent[node];
//     }

//     reverse(path.begin(),path.end());

//     cout << "Optimal Path: ";
//     for(int i=0;i<path.size();i++) {
//         cout << path[i];
//         if(i != path.size()-1) cout << " -> ";
//     }
//     cout << endl;

//     cout << "Total Cost: " << dist[goal] << endl;
//     cout << "Expanded Nodes: " << expanded << endl;

//     return 0;
// }








#include<bits/stdc++.h>

using namespace std;

using pii = pair<int, int>; // {cost, node}

int uniformCostSearch( int start, int target, const vector<vector<pii>>& adj ) {
    int n = adj.size();

    vector<int> cost(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (currentCost > cost[node])
            continue;

        if (node == target)
            return currentCost;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int edgeCost = edge.second;
            int newCost = currentCost + edgeCost;

            if (newCost < cost[neighbor]) {
                cost[neighbor] = newCost;
                pq.push({newCost, neighbor});
            }
        }
    }

    return -1; // Target unreachable
}

int main() {
    int n = 4;
    vector<vector<pii>> adj(n);

    // Add edges: {neighbor, cost}
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 1});

    int minCost = uniformCostSearch(0, 3, adj);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}