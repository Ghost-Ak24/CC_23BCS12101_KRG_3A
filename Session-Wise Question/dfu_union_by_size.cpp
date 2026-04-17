#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
   int n , m;
   cin>>n>>m;

    vector<vector<int>> adj = {
        {4,2},        
        {1,2},      
        {1,3},      
        {4,5}            
    };

    DSU dsu(n);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (u < v) { // avoid duplicate edges
                dsu.unionBySize(u, v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> Parent: " << dsu.findUPar(i) << endl;
    }

    return 0;
}