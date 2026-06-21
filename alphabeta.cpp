#include <bits/stdc++.h>
using namespace std;

int alphaBeta(int depth, int index, bool isMax, int arr[], int alpha, int beta) {

    // leaf node
    if (depth == 2) return arr[index];

    if (isMax) {
        int best = -1000;

        int left = alphaBeta(depth + 1, index * 2, false, arr, alpha, beta);
        best = max(best, left);
        alpha = max(alpha, best);

        if (beta <= alpha) return best; // PRUNE

        int right = alphaBeta(depth + 1, index * 2 + 1, false, arr, alpha, beta);
        best = max(best, right);
        alpha = max(alpha, best);

        return best;
    }

    else {
        int best = 1000;

        int left = alphaBeta(depth + 1, index * 2, true, arr, alpha, beta);
        best = min(best, left);
        beta = min(beta, best);

        if (beta <= alpha) return best; // PRUNE

        int right = alphaBeta(depth + 1, index * 2 + 1, true, arr, alpha, beta);
        best = min(best, right);
        beta = min(beta, best);

        return best;
    }
}

int main() {

    int arr[] = {3, 5, 2, 9};

    cout << alphaBeta(0, 0, true, arr, INT_MIN, INT_MAX);

    return 0;
}