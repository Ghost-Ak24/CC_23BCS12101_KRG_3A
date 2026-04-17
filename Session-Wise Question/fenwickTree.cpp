#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    // Add 'val' at index 'i'
    void update(int i, int val) {
        for (; i <= n; i += (i & -i)) {
            bit[i] += val;
        }
    }

    // Prefix sum from 1 to i
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & -i)) {
            sum += bit[i];
        }
        return sum;
    }

    // Range sum [l, r]
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};


int main() 
{
    FenwickTree ft(5);

    ft.update(1, 2);
    ft.update(2, 3);
    ft.update(3, 5);

    cout << ft.query(3) << endl;        // 10
    cout << ft.rangeQuery(2, 3) << endl;
}