#include <bits/stdc++.h>
using namespace std;

int solve(int curr, int prev, vector<int>& arr, vector<vector<int>>& dp) {
    if (curr == arr.size())
        return 0;

    // shift prev by +1
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // option 1: skip
    int notTake = solve(curr + 1, prev, arr, dp);

    // option 2: take
    int take = 0;
    if (prev == -1 || arr[curr] > arr[prev]) {
        take = 1 + solve(curr + 1, curr, arr, dp);
    }

    return dp[curr][prev + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    
    // dp[curr][prev+1]
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, -1, arr, dp);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(arr);
}