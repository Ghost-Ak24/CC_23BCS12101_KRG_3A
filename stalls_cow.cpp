#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid)) {
            ans = mid;      // possible, try bigger distance
            low = mid + 1;
        } else {
            high = mid - 1; // not possible, reduce distance
        }
    }
    return ans;
}

int main() {
    int n, cows;
    cin >> n >> cows;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << aggressiveCows(stalls, cows);

    return 0;
}