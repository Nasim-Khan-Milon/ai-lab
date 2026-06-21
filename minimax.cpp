#include <bits/stdc++.h>
using namespace std;

// Minimax function
int minimax(vector<int> tree, int index, bool isMax) {

    // If leaf node
    if (index >= tree.size())
        return 0;

    // If leaf level values
    if (index >= tree.size() / 2)
        return tree[index];

    // If MAX turn
    if (isMax) {
        int left = minimax(tree, 2 * index + 1, false);
        int right = minimax(tree, 2 * index + 2, false);
        return max(left, right);
    }

    // If MIN turn
    else {
        int left = minimax(tree, 2 * index + 1, true);
        int right = minimax(tree, 2 * index + 2, true);
        return min(left, right);
    }
}

int main() {

    // Represent tree in array form
    //          0
    //       0     0
    //     3  5   2  9
    vector<int> tree = {0, 0, 0,0, 0, 0, 0, 3, 5, 2, 9,5, 6, 7, 8};

    int result = minimax(tree, 0, true);

    cout << "Optimal value = " << result << endl;

    return 0;
}