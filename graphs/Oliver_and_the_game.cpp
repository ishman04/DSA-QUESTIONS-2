#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;    // Adjacency list for the tree
vector<int> depth;          // Depth of each node
vector<int> entry;          // DFS entry time for each node
vector<int> exitTime;       // DFS exit time for each node
int timer = 0;              // Timer to track DFS entry and exit times

// Depth First Search (DFS) to calculate entry, exit, and depth for each node
void dfs(int node, int parent, int d) {
    depth[node] = d;
    entry[node] = timer++;
    
    for (int neigh : adj[node]) {
        if (neigh != parent) {
            dfs(neigh, node, d + 1);
        }
    }

    exitTime[node] = timer++;
}

// Function to check if X is an ancestor of Y
bool isAncestor(int X, int Y) {
    return entry[X] <= entry[Y] && exitTime[X] >= exitTime[Y];
}

int main() {
    int N;
    cin >> N;  // Read number of houses

    adj.resize(N + 1);  // Resizing vectors to accommodate N houses (1-based index)
    entry.resize(N + 1);
    exitTime.resize(N + 1);
    depth.resize(N + 1);

    // Read the N-1 edges (roads)
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    // Preprocessing with DFS starting from house 1 (the King's Mansion)
    dfs(1, -1, 0);

    int Q;
    cin >> Q;  // Read number of queries

    // Process each query
    while (Q--) {
        int type, X, Y;
        cin >> type >> X >> Y;

        if (type == 0) {
            // Bob moves towards the King's Mansion
            if (isAncestor(X, Y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (type == 1) {
            // Bob moves away from the King's Mansion
            if (isAncestor(Y, X)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
