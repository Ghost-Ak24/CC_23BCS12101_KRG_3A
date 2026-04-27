#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>>& adj) {
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> visited(V, false);
    int mstSum = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        pair<int,int> temp = pq.top();
        pq.pop();

        int weight = temp.first;
        int node = temp.second;

        if (visited[node]) continue;

        visited[node] = true;
        mstSum += weight;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return mstSum;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << primMST(V, adj);

    return 0;
}
