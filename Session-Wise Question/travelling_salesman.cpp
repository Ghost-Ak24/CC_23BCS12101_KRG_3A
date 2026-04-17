#include <bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, vector<vector<int>> &cost, vector<vector<int>> &dp, int n) {
    
    // 🟢 Base case: all cities visited
    if(mask == (1 << n) - 1)
        return cost[pos][0];  // return to start

    // 🟢 Already computed
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // 🔥 Try all unvisited cities
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {  // not visited

            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city, cost, dp, n);

            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n = 4;

    vector<vector<int>> cost = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << tsp(1, 0, cost, dp, n);  // start from city 0
}