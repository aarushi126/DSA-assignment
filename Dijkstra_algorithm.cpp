#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void add_edge(vector<vector<pair<int, int>>>& adj_list, int u, int v, int w) {
    adj_list[u].push_back({ v, w });
    adj_list[v].push_back({ u, w });
}

void dijkstra(vector<vector<pair<int, int>>>& adj_list, int s, vector<int>& dist, vector<int>& prev) {
    int n = adj_list.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] : adj_list[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
}

void print_path(vector<int>& prev, int v) {
    if (v == -1) {
        return;
    }
    print_path(prev, prev[v]);
    cout << v << " ";
}

int main() {
    int n = 10; // number of vertices
    int m = 20; // number of edges
    vector<vector<pair<int, int>>> adj_list(n + 1);

    // build graph
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) {
            add_edge(adj_list, i, i + 1, i + 1);
        }
        if (i + 2 <= n) {
            add_edge(adj_list, i, i + 2, i + 2);
        }
    }

    // print vertices and edges
    cout << "Graph:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto [v, w] : adj_list[i]) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    // run Dijkstra's algorithm
    vector<int> dist, prev;
    dijkstra(adj_list, 1, dist, prev);

    // print shortest paths
    cout << "Shortest paths:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Shortest path from 1 to " << i << " is ";
        print_path(prev, i);
        cout << endl;
    }

    // print tree that results from Dijkstra's algorithm
    cout << "Tree:" << endl;
    for (int i = 1; i <= n; i++) {
        if (prev[i] != -1) {
            cout << i << " <- " << prev[i] << endl;
        }
    }

    return 0;
}
