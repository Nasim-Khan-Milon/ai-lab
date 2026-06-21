#include <bits/stdc++.h>
using namespace std;

string goal = "123456780";

int getX(int i) { return i / 3; }
int getY(int i) { return i % 3; }

// Manhattan Distance
int heuristic(string s) {
    int dist = 0;

    for (int i = 0; i < 9; i++) {
        if (s[i] == '0') continue;

        int val = s[i] - '1';
        dist += abs(getX(i) - getX(val)) + abs(getY(i) - getY(val));
    }

    return dist;
}

int main() {
    string start = "123406758";

    priority_queue< pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;

    map<string, int> g;

    pq.push(make_pair(heuristic(start), start));
    g[start] = 0;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    while (!pq.empty()) {

        string cur = pq.top().second;
        pq.pop();

        if (cur == goal) {
            cout << "Solved 8-puzzle!\n";
            return 0;
        }

        int z = cur.find('0');
        int x = z / 3, y = z % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {

                string next = cur;
                swap(next[z], next[nx * 3 + ny]);

                int newG = g[cur] + 1;

                if (!g.count(next) || newG < g[next]) {
                    g[next] = newG;
                    int f = newG + heuristic(next);
                    pq.push(make_pair(f, next));
                }
            }
        }
    }

    cout << "Not solvable / not found\n";
    return 0;
}